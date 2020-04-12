/*
https://www.acmicpc.net/problem/7620
7620 편집거리
문자열이 주어졌을 때, 이 문자열을 다른 문자열로 바꾸는 편집 스크립트를 작성하려고 한다. 편집 스크립트에서 사용할 수 있는 명령은 아래와 같이 총 네 가지가 있다.
추가 ('a'): 한 글자를 출력한다. 이 명령은 입력 문자열을 건드리지 않는다.
삭제 ('d'): 한 글자를 삭제한다. 이 명령은 입력 문자열에서 맨 앞 글자를 삭제하고, 아무것도 출력하지 않는다.
수정 ('m'): 한 글자를 수정한다. 즉, 입력 문자열에서 맨 앞 글자를 삭제하고, 바꾼 글자를 출력한다.
복사 ('c'): 한 글자를 복사한다. 입력에서 맨 앞 글자를 삭제하고, 삭제한 그 글자를 출력한다.
가장 짧은 편집 스크립트란, 추가, 삭제, 수정을 가장 적게 사용한 스크립트이다.
두 문자열이 주어졌을 때, 첫 번째 문자열을 두 번째 문자열로 바꾸는 가장 짧은 편집 스크립트를 작성하는 프로그램을 작성하시오. 

LCS, DP, bitwise
*/
#include <cstdio> // printf, scanf 사용
#include <cstring> // memset 사용
#include <algorithm> // std::min 사용

#define MAX_L 17001 // input string의 최대길이
#define A 0 // ADD
#define C 1 // COPY
#define D 2 // DELETE
#define M 3 // MODIFY
using std::min;
// 변수 선언부
char source[MAX_L]; // string 변환전 원본을 들고 있는 배열
char dest[MAX_L]; // string 변환후의 모습을 들고 있는 배열
int dp[2][MAX_L]; // dp[i][j] i 부터 j까지 연결할때 최소 편집거리를 저장하는 배열
unsigned char operation[((MAX_L) * (MAX_L)) / 4]; // 경로 되추적 배열
int sourceLen, destLen;

void input(){
	scanf("%s", source);
	scanf("%s", dest);
}

// operation이 2차원 배열일때 operation[i][j]와 동일하게 기능하도록 구현된 함수
int getOperation(int i, int j) {
	int index = (i * (destLen + 1)) + (j + 1);
	int row = index / 4;
	int col = index % 4;

	if (!col) {
		row--;
		col = 4;
	}

	// 현재 row 값을 가져와서
	unsigned char cur = operation[row];
	// bit 이동
	unsigned char val = (cur >> (4 - col) * 2);
	// 이동된 bit에 들어있는 실제 값 추출
	unsigned char ans = val &  3;

	return (int)ans;
}

// operation이 2차원 배열일때 operation[i][j] = val 와 동일하게 기능하도록 구현된 함수
void setOperation(int i, int j, int val) {
	int index = (i * (destLen + 1)) + (j + 1);
	int row = index / 4;
	int col = index % 4;

	if (!col) {
		row--;
		col = 4;
	}

	// 현재 row 값을 가져와서
	unsigned char cur = operation[row];
	// 이전에 들어 있던 값 확인
	unsigned char prev = (cur >> (4 - col) * 2) & 3;
	// 이전에 들어 있던 값에 실제 대응되는 char 값 추출
	unsigned char clean = (prev << (4 - col) * 2);
	// 지금 저장하려는 val를 bit이동
	unsigned char ans = (val << (4 - col) * 2);
	// 현재 row값에서 기존값 제거 후 새 값 저장
	cur -= clean;
	cur += ans;
	// 새로 생성한 값 row에 저장
	operation[row] = cur;
}

void init(){
	sourceLen = strlen(source);
	destLen = strlen(dest);
	memset(dp, 0, sizeof(dp));
	memset(operation, 0, sizeof(operation));

	for(int i=1; i<=sourceLen; i++) {
		if (i == 0 || i == 1) {
			dp[i][0] = i;
		}
		setOperation(i, 0, D);
	}

	for(int j=1; j<=destLen; j++) {
		dp[0][j] = j;
		setOperation(0, j, A);
	}
}

void findMinEditDist() {
	for(int i=1; i<=sourceLen; i++) {
		// 기존 dp[i][j]와 동일하지만 dp배열은 출력에 필요없으니 2줄(0,1)로 최적화
		int cur = i % 2; // 현재 값을 0 or 1로 변환
		int prev = !cur; // 변환 된 현재 값의 반대값 1 or 0 저장
		dp[cur][0] = i;
		for(int j=1; j<=destLen; j++) {
			// 현재 i-1번째 위치와 j-1번째 위치의 문자가 같은지 확인
			int val = source[i-1] == dest[j-1] ? 0 : 1;
			// dp[cur][j]로 도달할때 3방향 중 가장 가중치가 작은 방향을 선택
			dp[cur][j] = min(dp[prev][j-1] + val, min(dp[prev][j] + 1, dp[cur][j-1] + 1));

			// 현재 dp[cur][j]를 만든 방향에 따라 operatrion 선택 후 저장
			int op = 0;
			if (dp[cur][j] == dp[prev][j-1] + val) {
				op = val ? M : C;
			} else if (dp[cur][j] == dp[prev][j] + 1) {
				op = D;
			} else if (dp[cur][j] == dp[cur][j-1] + 1) {
				op = A;
			}

			setOperation(i, j, op);
		}
	}
}

void printShortestEditScript(int start, int end) {
	// (0,0)에 도달시 종료
	if (start == 0 && end == 0) return;
	int currentOperation = getOperation(start, end);

	// currentOperation의 종류에 따라 다음범위 탐색 후 출력
	switch (currentOperation) {
		case M: // M은 NW에서 오기 때문에 해당영역 탐색 후 dest의 값으로 변경된 값 출력
			printShortestEditScript(start-1, end-1);
			printf("m %c\n", dest[end - 1]);
			break;
		case C: // C는 NW에서 오기 때문에 해당영역 탐색 후 source의 값으로 기존 값 출력
			printShortestEditScript(start-1, end-1);
			printf("c %c\n", source[start - 1]);
			break;
		case D: // D는 N에서 오기 때문에 해당영역 탐색 후 지워진 source의 값 출력
			printShortestEditScript(start-1, end);
			printf("d %c\n", source[start-1]);
			break;
		case A: // A는 W에서 오기 때문에 해당영역 탐색 후 추가된 dest의 값 출력
			printShortestEditScript(start, end-1);
			printf("a %c\n", dest[end-1]);
			break;
		default:
			break;
	}
}

int main(void){
	input();					// 입력
	init();		  			// 사용변수들 초기화
	findMinEditDist();// 최소 편집거리 찾기
	printShortestEditScript(sourceLen, destLen); // 찾은 편집스크립트 출력

	return 0;
}

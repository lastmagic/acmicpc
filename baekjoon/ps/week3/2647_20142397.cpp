/*
https://www.acmicpc.net/problem/2647
검은점과 하얀점 연결
2n개의 점이 x축의 좌표 1,2,...2n에 놓여 있다. 그 중 n개는 검은 점이고, n개는 하얀 점이다. 하나의 검은 점과 하나의 하얀 점을 연결하여 한 쌍을 만들면, 모두 n개의 쌍이 만들어진다. 한 쌍의 점을 연결할 때는, 왼쪽 점에서 출발하여 수직으로 올라가고, 거기서 수평으로 오른쪽으로 간 후, 다시 수직으로 내려가서 연결하면 하나의 길이 생긴다. 이렇게 생긴 n개의 길들은 서로 겹쳐서는 안되고, 서로 교차해서도 안 된다. 모든 길의 거리의 합을 가장 작게 하도록 n개의 길을 만드는 프로그램을 작성하시오. 단, 거리의 단위는 수직, 수평 모두 1이다.
그림 1의 경우 다른 방법으로 연결할 수도 있지만, 위 방법이 최소 연결 방법이고 거리의 합이 31이다. 그림 2의 경우도 다른 방법이 있지만, 위 방법이 최소 연결이며 거리의 합은 40이다.

입력
첫째 줄에는 점의 개수를 나타내는 정수 2n이 주어진다. 2n은 100이하의 정수이다. 그 다음 줄에는 n개의 0과 n개의 1로 이루어진 문자열이 주어진다. 0은 하얀 점이고, 1은 검은 점이다. 왼쪽부터 차례로 좌표 1,2,...2n에 해당한다.

출력
첫째 줄에는 길의 거리의 합을 출력한다. 다음 n개의 줄의 각 줄에는 연결되는 한 쌍의 점들의 좌표를 나타내는 두 정수를 출력한다. 두 정수 사이에는 빈칸이 하나 있다. 앞의 정수가 뒤 정수보다 작아야하고, n개의 줄은 앞 정수가 커지는 순서로 출력한다.
*/
#include <cstdio> // printf, scanf 사용
#include <cstring> // memset 사용
#include <algorithm> // std::max 사용 (현재 코드에서 제거해도 컴파일에러가 나지 않는 이유는 vector header에 포함되어 있기 때문, 명시적으로 넣어주는게 좋다.)
#include <vector> // std::vector 사용
#define INF 1234567890 // dp에서 아직 초기화 되지 않은 갈 수 없는 값을 임의로 Infinite라 지정
#define MAX_N 111 // n의 최대 범위는 100, 혹시 모를 index 에러 방지를 위해 111로 설정

// 알고리즘만 풀기 용도면 using namespace std로 가능하지만
// std에 속한 어느것을 쓰는지 확인하기 위해 명시적으로 나열.
using std::vector; 
using std::pair;
using std::max;
using pii=pair<int,int>;

// 변수 선언부
int n; // 문제에서의 2n 값 저장
int point[MAX_N]; // 좌표마다 흰점인지 검은점인지 가지고 있는 배열
int dp[MAX_N][MAX_N]; // dp[i][j] == i 부터 j 지점까지 연결선 총합의 최소값
int height[MAX_N][MAX_N]; // height[i][j] == i 부터 j 지점까지 사용된 높이의 최대값.
int parent[MAX_N][MAX_N]; // parent[i][j] == i 와 j 를 연결 할 때 direct로 연결 된 점
vector<pii> ans; // {시작점, 종료점}을 저장하는 벡터
void input(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%1d", &point[i]);
	}
}

void init(){
  memset(dp, 0, sizeof(dp));
  memset(height, 0, sizeof(height));
	memset(parent, 0 , sizeof(parent));
	for(int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			dp[i][j] = INF;
      parent[i][j] = -1;
		}
	}
}

void output(){
	printf("%d\n", dp[1][n]);
	for(auto it : ans) {
		printf("%d %d\n", it.first, it.second);
	}
}

// 현재 start, end point가 연결되어 있는지 판단.
bool isLinked(int start, int end) {
	if (start >= end) return false;
	return dp[start][end] != INF;
}

void findMinLink() {
	// diagoanl 1부터 CMM 적용, 최적화시 d += 2 로 수정가능.
	for(int d = 1; d <= n-1; d += 1) {
		for(int i=1; i <= n-d; i++) {
			int j = i + d;
			// i와 j가 서로 다른색이고, (기존 i+1, j-1이 연결되어 있거나 || d가 1인 경우) i와 j를 연결하여 갱신
			if ((isLinked(i+1, j-1) || d == 1) && point[i] + point[j] == 1) {
				height[i][j] = height[i+1][j-1] + 1;
				dp[i][j] = (2 * height[i][j]) + d + dp[i+1][j-1];
				parent[i][j] = i;
			}
      // i, j 사이에서 연결 가능하고, dp가 최소가 되는 k값을 찾아서 갱신
			for (int k=i+1; k <= j-1; k++) {
				if (!isLinked(i, k) || !isLinked(k+1, j)) continue;
				if (dp[i][j] > dp[i][k] + dp[k+1][j]) {
					dp[i][j] = dp[i][k] + dp[k+1][j];
					height[i][j] = max(height[i][k], height[k+1][j]);
					parent[i][j] = k;
				}
			}
		}
	}
}

void findAns(int start, int end) {
  int cur = parent[start][end];
  // 재귀 조건이 끝났거나, start, end와 직접 연결된 점이 없다면 종료.
	if (start >= end || cur == -1) return;
  // start와 end가 서로 직접연결되었다면 정답 추가 및 다음 범위 탐색
	if (cur == start) {
		ans.push_back({start, end});
		findAns(start+1, end-1);
	} else { // start와 end가 cur를 거쳐 간접연결 되었다면 간접 연결 범위 탐색
		findAns(start, cur);
		findAns(cur+1, end);
	}
}

int main(void){
	input(); // 입력
	init(); // 사용변수들 초기화
	findMinLink(); // 모든점을 연결하는 방법중 최소합 찾기
	findAns(1, n); // 찾은 최소합에 포함되는 연결점 찾기
	output(); // 정답출력
	return 0;
}

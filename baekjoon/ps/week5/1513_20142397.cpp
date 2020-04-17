/*
https://www.acmicpc.net/problem/1513
경로찾기
세준이는 크기가 N*M인 직사각형 도시에 살고 있다. 또, 세준이의 집은 (1, 1)에 있고, 학원은 (N, M)에 있고, 오락실이 C개 있다.
세준이의 현재 위치가 (r, c) 일 때, (r+1, c) 또는 (r, c+1)로만 이동할 수 있다. 오락실을 방문할 때는 규칙이 하나 있는데, 오락실 번호가 증가하는 순서대로 가야한다는 것이다. 2번 오락실을 먼저 가고, 그 후에 1번 오락실을 가면 안 되고, 2번 오락실을 가려면, 그 전에 아무 오락실도 가지 않거나, 1번 오락실을 방문했을 때만 가능하다.
세준이는 오락실을 K번 방문해서 학원에서 도착하는 경로의 경우의 수가 궁금해지기 시작했다. 오락실을 0개 방문했을 때부터, C개 방문했을 때 까지 경우의 수를 출력하는 프로그램을 작성하시오.

KeyWord: DP, MEMORIZATION
TIP: %는 분배법칙이 적용되기 때문에 (A+B)%M == ((A%M) + (B%M)) %M,덧셈할때 마다 MOD를 취하고 최종적으로 MOD를 취해주면 원하는 결과를 얻을 수 있다.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_N 55
#define MOD 1000007

using std::vector;

// 현재 문제에서의 단위 벡터
const int dx[] = {0, -1};
const int dy[] = {-1, 0};
int n,m,c;

// 오락실의 위치를 저장
int arr[MAX_N][MAX_N]; 
// D[i][j][k][l] i,j 까지 왔을때 총 들린 오락실이 k개 이고, 마지막으로 들린 오락실의 번호가 l인 경우의 수
int D[MAX_N][MAX_N][MAX_N][MAX_N]; 
vector <int> ans;
void input(){
	scanf("%d %d %d", &n ,&m, &c);
	for(int i=0; i<c; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		arr[y][x] = i+1;
	}
}

void init(){
	memset(D, -1, sizeof(D));
}

bool isInner(int y, int x) {
	return (y > 0 && y <= n && x > 0 && x <= m);
}

int dp(int y, int x, int arcadeCnt, int prevVisitedArcade) {
	if (!isInner(y, x)) return 0;

	int& ret = D[y][x][arcadeCnt][prevVisitedArcade];
	if (ret != -1) return ret;

	ret = 0;
	
	int curArcade = arr[y][x];

	if (curArcade > prevVisitedArcade) { //현재지점이 게임장 번호가 
		return 0;
	} else if (curArcade == 0) { // 현재지점이 게임장이 아닌경우 위 또는 아래방향에서 내려오는 경우의 합을 구하면 된다.
		for(int dir=0; dir<2; ++dir) {
			int nextX = x + dx[dir];
			int nextY = y + dy[dir];
			ret += ((dp(nextY, nextX, arcadeCnt, prevVisitedArcade)) % MOD);
		}
		ret %= MOD;
	} else if (curArcade == prevVisitedArcade) {
		for(int i=0; i<prevVisitedArcade; ++i) {
			for(int dir=0; dir<2; ++dir) {
				int nextX = x + dx[dir];
				int nextY = y + dy[dir];
				ret += ((dp(nextY, nextX, arcadeCnt - 1, i) % MOD));
			}
			ret %= MOD;
		}
	}

	return ret;
}


void process(){
	int arcadeNumWithHome = arr[1][1];

	if (!arcadeNumWithHome){ // 집과 오락실 위치가 동일하지 않은 경우
		D[1][1][0][0] = 1;
	} else { // 집과 오락실의 위치가 동일 한 경우, 집에서 출발할때부터 이미 오락실을 지나간 것으로 판단.
		D[1][1][1][arcadeNumWithHome] = 1;
	}

	// (n,m,0,0) ~ (n,m,c,c) 까지 반복, i는 현재 게임장 개수, j는 마지막으로 사용한 게임장번호
	for(int i=0; i<=c; ++i) {	
		int curAns = 0;
		for(int j=0; j<=c; ++j) {
			curAns += (dp(n, m, i, j)) % MOD;
		}
		curAns %= MOD;
		ans.push_back(curAns);
	}
}

void output() {
	for(auto it: ans) {
		printf("%d ", it);
	}
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

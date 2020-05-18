/*
https://www.acmicpc.net/problem/10265
남규는 동기들과 엠티를 가기 위해 버스를 대절했다. 그런데 과사의 실수로 대절버스의 인원이 잘못되어 남규의 동기들을 모두 태울 수 없었다. 이 와중에 동기들은 화를 내며 다음과 같은 말들을 주고받았다.
재혁: 동우가 안 가면 나도 안 간다.
동우: 세종이가 안 가면 난 안 갈래.
버스에 태울 수 있는 인원수는 한정되어 있는데 모두들 다른 누군가가 가지 않으면 자신도 가지 않겠다 하니 남규는 신경이 뻗쳤다. 게다가 술을 너무 많이 샀기 때문에 최대한 많은 인원을 데려가지 않으면 안 되는 상황이었다.
각 사람이 원하는 같이 갈 사람이 주어질 때, 버스에 태울 수 있는 사람은 최대 몇 명인지 알아내시오.

Keyword: SCC, Knapsack, DP
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 1005
#define WHITE 0 // 미방문
#define GRAY -1 // 방문중이지만 아직 방문이 끝나지 않은 (재귀호출 종료 X)
#define BLACK 1 // 방문완료 >= 1

int N, K;
int adj[MAX_N];
int visited[MAX_N];
int parent[MAX_N];
int componentNum = 1;
int sccSize[MAX_N];
int componentSize[MAX_N];
int dp[MAX_N];
int ans;

int dfs(int x) {
	visited[x] = GRAY;
	int next = adj[x];
	int connectedCompNum;

  // 다음 vertex를 처음 방문하는 경우 다음 vertex로 dfs
	if (visited[next] == WHITE) {
		connectedCompNum = dfs(next);
		parent[next] = x;
	}
	// 다음 vertex를 현재 방문중인 경우 Back Edge이므로 circuit 존재 확인, 발견한 circuit(scc)의 크기 확인
	else if (visited[next] == GRAY) {
		sccSize[componentNum] = 1;
		for (int i = next; i != x; i = adj[i]) {
			sccSize[componentNum]++;
		}
		connectedCompNum = componentNum++;
	}
	// 다음 vertex가 이미 방문완료 되어 컴포넌트를 이루고 있는 경우 현재 vertex를 해당 component에 연결
	else if (visited[next] >= BLACK) {
		connectedCompNum = visited[next];
	}
	visited[x] = connectedCompNum;

	return connectedCompNum;
}

void input() {
  scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
    scanf("%d", &adj[i]);
	}
}

void init() {
  memset(visited, 0, sizeof(visited));
  memset(parent, 0 , sizeof(parent));
  memset(sccSize, 0 , sizeof(sccSize));
  memset(componentSize, 0 , sizeof(componentSize));
  memset(dp, 0 , sizeof(dp));
  ans = 0;
}

void doDfs() {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
}

void calcComponentSize() {
  // 각 컴포넌트 크기 계산
	for (int i = 1; i <= N; i++) {
		componentSize[visited[i]]++;
	}
}

void findSCC() {
  doDfs();
  calcComponentSize();
}

void findAns() {
  dp[0] = 1;
  // sccSize와 componentSize를 이용해서 sccSize <= x <= componentSize 인 경우의 0-1 knapsack 실행 
	for (int i = 1; i < componentNum; i++) {
		int curSccSize = sccSize[i];
		int curComponentSize = componentSize[i];
		for (int j = K - curSccSize; j >= 0; j--) {
			if (dp[j]) {
				for (int k = j + curSccSize; k <= j + curComponentSize && k <= K; k++) {
					dp[k] = 1;
          if (ans < k) {
            ans = k;
          }
				}
			}
		}
	}
}

void process() {
  findSCC();
  findAns();
}

void output() {
  printf("%d", ans);
}

int main() {
  input();
  init();
  process();
  output();
  return 0;
}
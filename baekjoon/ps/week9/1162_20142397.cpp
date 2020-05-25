/*
https://www.acmicpc.net/problem/1162
도로포장
준영이는 매일 서울에서 포천까지 출퇴근을 한다. 하지만 잠이 많은 준영이는 늦잠을 자 포천에 늦게 도착하기 일쑤다. 돈이 많은 준영이는 고민 끝에 K개의 도로를 포장하여 서울에서 포천까지 가는 시간을 단축하려 한다.
문제는 N개의 도시가 주어지고 그 사이 도로와 이 도로를 통과할 때 걸리는 시간이 주어졌을 때 최소 시간이 걸리도록 하는 K개의 이하의 도로를 포장하는 것이다. 도로는 이미 있는 도로만 포장할 수 있고, 포장하게 되면 도로를 지나는데 걸리는 시간이 0이 된다. 또한 편의상 서울은 1번 도시, 포천은 N번 도시라 하고 1번에서 N번까지 항상 갈 수 있는 데이터만 주어진다.

Keyword: Dijkstra, Graph, Priority Queue, DP

Memo: 처음에는 Dijkstra로 dp[n][0]를 구하고 bfs로
dp[n][k]를 구하는 점화식을 세워 풀었는데 시간초과에 막혔다.
Dijkstra쪽은 문제가 없었던 거 같은데 bfs가 생각보다 오버헤드가 크게 나왔던 것 같다.
bfs로직을 Dijkstra내부에 녹이면서 풀 수 있었던 문제다.
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using std::pair;
using std::vector;
using std::priority_queue;
using std::min;
using pii=pair<int,int>;
using lint=long long;
#define MAX_N 10011
#define MAX_K 21
const lint INF = 0x7f7f7f7f7f7f7f7f;
typedef struct element {
  lint v; //vertex number
  lint w; // weight
  lint _k; // Number of Unused Edge
} element;

// PQ 사용시 정렬기준을 w로 하기 위해서 cmp 구조체 추가
struct cmp{
    bool operator()(element a, element b){
        return a.w > b.w;
    }
};

int N,M,K;
lint dp[MAX_N][MAX_K]; // dp[N][K] == 1번 정점에서 N번 정점까지 K개의 Edge의 가중치를 지울때 최단경로 값
vector<pii> adj[MAX_N]; // adj[u] == {v, w}
priority_queue<element, vector<element>, cmp>pq;

void input(){
  scanf("%d %d %d", &N, &M, &K);
  for (int i=1; i<=M; i++) {
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
}

void init(){
  memset(dp, 0x7f, sizeof(dp));
}

// 기존 dp[next][0] 만 구했던 dijkstra가 아니라 dp[next][_k], dp[next][_k+1] 을 구할 수 있도록 점화식 수정
void dijkstra(int start) {
  dp[start][0] = 0;
  pq.push({start, 0, 0});

  while(!pq.empty()) {
    element cur = pq.top();
    lint u = cur.v;
    lint w = cur.w;
    lint _k = cur._k;

    pq.pop();
    
    if (w > dp[u][_k]) continue;

    for (auto &e : adj[u]) {
      int next = e.first;
      int cost = e.second;

      if (dp[next][_k] > w + cost) {
        dp[next][_k] = w + cost;
        pq.push({ next, dp[next][_k], _k });
      }

      if ((_k+1 <= K) && (dp[next][_k + 1] > w)){
        dp[next][_k + 1] = w;
        pq.push({ next, w, _k + 1 });
      }
    }
  }
}

void process(){
  dijkstra(1);
}

void output(){
  printf("%lld", dp[N][K]);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

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
// pq의 element 구조체 추가
typedef struct element {
  lint v;
  lint w;
  lint _k;
} element;

struct cmp{
    bool operator()(element a, element b){
        return a.w > b.w;
    }
};

int N,M,K;
int visited[MAX_N];
lint dp[MAX_N][MAX_K];
vector<pii> adj[MAX_N];
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
  memset(visited, 0, sizeof(visited));
}

bool isCurrentPromise(int v, int w, int k, int cost) {
  return (dp[v][k] > w + cost);
}
bool isNextPromise(int v, int w, int k) {
  return (k+1 <= K) && (dp[v][k + 1] > w);
}

void pushElementIfNeeded(int v, int w, int k, int cost){
  if (isCurrentPromise(v, w, k, cost)) {
    dp[v][k] = w + cost;
    pq.push({ v, dp[v][k], k });
  }

  if (isNextPromise(v, w, k)){
    dp[v][k + 1] = w;
    pq.push({ v, w, k + 1 });
  }
}

// 그냥 다익스트라가 아닌 현재 지운 edge의 갯수 (_k)를 포함한 다익스트라.
void dijkstra(int start) {
  dp[start][0] = 0;
  pq.push({start, 0, 0});

  while(!pq.empty()) {
    element cur = pq.top();
    lint u = cur.v;
    lint w = cur.w;
    lint _k = cur._k;

    pq.pop();

    if (w > dp[u][_k]) continue; // 현재 1 -> u 까지 _k의 edge를 지운 경로의 최소값이 w보다 작으면 유망하지 않으므로 continue

    for (auto &e : adj[u]) { // 현재 u와 연결된 edge들 판단하여 최소값이 갱신되는 경우 갱신 후 pq에 추가
      int next = e.first;
      int cost = e.second;

      pushElementIfNeeded(next, w, _k, cost);
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

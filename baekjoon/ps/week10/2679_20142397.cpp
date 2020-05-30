/*
https://www.acmicpc.net/problem/2679
맨체스터의 도로

맨체스터에 있는 도로는 모두 일방 통행이다. 또한 이 도로는 모두 1시간에 지나갈 수 있는 차의 개수 제한이 있다. 길(경로)에도 차의 개수 제한이 있는데, 이것은 이 길에 있는 도로의 제한 중 최솟값이다.
A에서 B로 가는 중복 비율은 A에서 B로 가는 모든 길을 동시에 이용했을 때 1시간 동안 B에 도착할 수 있는 차의 최대 개수와 길 1개를 이용했을 때 도착할 수 있는 최대 개수의 비율이다.
최소 중복 비율은 길 1개를 이용했을 때 도착할 수 있는 최대 개수가 가장 큰 값이 된다.
맨체스터의 도로 정보와 A, B가 주어졌을 때, 최소 중복 비율을 구하는 프로그램을 작성하시오.

Keyword: Graph, Maximum Flow, Network Flow, Edmons Karp
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using std::pair;
using std::vector;
using std::priority_queue;
using std::min;
using std::queue;
using pii=pair<int,int>;
using lint=long long;

#define MAX_N 1001

const lint INF = 0x7f7f7f7f7f7f7f7f;
int TC;
int N,E,A,B;
lint maxFlow; // graph의 maxFlow
lint maxSingleFlow; // graph의 path 중 path에 포함된 edge의 min값이 가장 큰 경우의 min
double ans;
int capacity[MAX_N][MAX_N]; // graph의 용량
int flow[MAX_N][MAX_N]; // graph의 현재 flow값
vector<int> adj[MAX_N]; // graph의 연결상태
bool visited[MAX_N];
int parent[MAX_N];

void init(){
  memset(capacity, 0, sizeof(capacity));
  memset(flow, 0, sizeof(flow));
  memset(visited, 0 , sizeof(visited));
  for (int i=0; i<MAX_N; i++) {
    adj[i].clear();
  }

  maxFlow = 0;
  maxSingleFlow = 0;
  ans = 0;
}

void input(){
  scanf("%d %d %d %d", &N, &E, &A, &B);
  for(int i=0; i<E; i++) {
    int u,v,w;
    scanf("%d %d %d", &u, &v, &w);
    capacity[u][v] += w;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int findResidual(int v1, int v2) {
  return capacity[v1][v2] - flow[v1][v2];
}

bool isPromise(int now, int next) {
  return ((parent[next] == -1) && (findResidual(now, next) > 0));
}

lint findCurMin(int source, int sink) {
  lint curMin = INF;
  for (int i = sink; i != source; i = parent[i]) {
    curMin = min((lint)findResidual(parent[i], i), curMin);
  }

  return curMin;
}

void updateCurFlow(int source, int sink, lint curMin) {
  for (int i = sink; i != source; i = parent[i]) {
    flow[parent[i]][i] += curMin;
    flow[i][parent[i]] -= curMin;
  }
}

void edmondsKarp(int source, int sink) {
  while (true) {
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(source);
    parent[source] = source;

    while (!q.empty() && parent[sink] == -1) {
      int now = q.front();
      q.pop();
      
      for (auto next: adj[now]) {
        if (isPromise(now, next)) {
          parent[next] = now;
          q.push(next);
        }
      }
    }

    if (parent[sink] == -1) {
      return;
    }

    lint curMin = findCurMin(source, sink);
    updateCurFlow(source, sink, curMin);

    maxFlow += curMin;
  }
}

// Find maxFlow of graph
void findMaxFlow(int source, int sink) {
  edmondsKarp(source, sink);
}

// Find maxSingleFlow of graph
void findMaxSingleFlow(int source, int sink) {
  priority_queue<pii> pq;
  pq.push({ INF, source });
  while(!pq.empty()) {
    pii now = pq.top();
    int w = now.first;
    int v = now.second;
    pq.pop();

    if (!visited[v]) {
      if(v == B) {
        maxSingleFlow = w;
        break;
      }

      visited[v] = true;
      for (int i=0; i<N; i++) {
        if (capacity[v][i]) {
          pq.push({min(w, capacity[v][i]), i});
        }
      }
    }
  }
}

void calcAns() {
  ans = ((double)maxFlow / (double)maxSingleFlow);
}

void process(){
  findMaxSingleFlow(A, B);
	findMaxFlow(A, B);
  calcAns();
}

void output(){
  printf("%.3lf\n", ans);
}

int main(void){
  scanf("%d", &TC);
  for (int i=0; i<TC; i++) {
    init();
    input();
    process();
    output();
  }

	return 0;
}

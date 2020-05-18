/*
https://www.acmicpc.net/problem/1939
중량제한
N(2≤N≤10,000)개의 섬으로 이루어진 나라가 있다. 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.
영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다. 물품을 생산하다 보면 공장에서 다른 공장으로 생산 중이던 물품을 수송해야 할 일이 생기곤 한다. 그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다. 만약 중량제한을 초과하는 양의 물품이 다리를 지나게 되면 다리가 무너지게 된다.
한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오.

Keyword: BFS, Graph, Parametric Search, (MST)
P.S: MST 풀이법 공부 필요
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1234567890

using std::pair;
using std::vector;
using std::queue;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int factory1, factory2;
vector<pii> graph[100001];
lint ans = 0;
bool visited[100001];
void input(){
  scanf("%d %d", &n, &m);
  int a, b, w;
	// Multi Edge를 허용하고 있지만 실질적으로 가장 w가 큰 Edge만 남겨야 이후 과정이 편하다.
  for (int i=0; i<m; i++) {
    scanf("%d %d %d", &a, &b, &w);
    
    bool hasElement = false;
    for (auto &cur : graph[a]) {
			// 기존 a,b에 Edge가 있다면 w가 큰경우에만 추가
      if (cur.first == b) {
        hasElement = true;
        if (cur.second < w) {
          cur.second = w;
					// b,a 에 Edge도 갱신
					for (auto &pairCur : graph[b]) {
						if (pairCur.first == a) {
							pairCur.second = w;
						}
					}
        }
      }
    }
		// 기존 a,b 에 Edge가 없다면 추가
    if (!hasElement) {
      graph[a].push_back({b, w});
			graph[b].push_back({a, w});
    }
  }
  scanf("%d %d", &factory1, &factory2);
}

void init(){
	memset(visited, 0, sizeof(visited));
}

void bfs(int vertex, int maxWeight){
  queue <int> q;
  q.push(vertex);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if(visited[now]) continue;
    visited[now] = true;
		for (auto &v : graph[now]) {
			int next = v.first;
			int weight = v.second;
			if (weight >= maxWeight  && !visited[next]) {
				q.push(next);
			}
		}
  }
}

bool isConnectable() {
	return visited[factory2];
}

// 결국 이분탐색이지만 이분탐색 시 결정 조건이 bfs로 부터 나옴
void parametericSearch(int left, int right){
	int mid = (left + right) / 2;
	if (left > right) {
		return;
	}
	
	init();
	bfs(factory1, mid);
	if (isConnectable()) {
		if (ans < mid) {
			ans = mid;
		}
		
		parametericSearch(mid+1, right);
	} else {
		parametericSearch(left, mid-1);
	}
}

void process(){
	parametericSearch(0, 1000000000);
}

void output(){
  printf("%lld", ans);
}

int main(void){
	input();
	init();
	process();
	output();

	return 0;
}

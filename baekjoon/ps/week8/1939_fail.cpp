/*
차후 공부
MST 를 이용한 풀이법 실패
이유 => MST 만들기는 성공 하였으나 
Union Find 중
한 node가 여러명의 부모를 가지게 되는 경우가 발생
=> 해당 경우를 어떻게 처리하는지 고민 필요
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define INF 1234567890

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int factory1, factory2;
typedef struct edge {
  int prev;
  int next;
  int weight;
}edge;
vector<pii> graph[100001];
vector<edge> e;
int parent[100001];
int root[100001];
lint ans;
void input(){
  scanf("%d %d", &n, &m);
  int a, b, w;
  for (int i=0; i<m; i++) {
    scanf("%d %d %d", &a, &b, &w);
    // [a][b] 가 없을 때
    // [a][b] 가 있는데 w가 더 클때
    if (a>b) {
      parent[a] = b;
    } else {
      parent[b] = a;
    }
    bool hasElement = false;
    for (auto &cur : graph[a]) {
      if (cur.first == b) {
        hasElement = true;
        if (cur.second < w) {
          cur.second = w;
        }
      }
    }
    if (!hasElement) {
      graph[a].push_back({b, w});  
    }
  }
  for (int i=1; i<=n; i++) {
    for(auto &it : graph[i]) {
      int b = it.first;
      int w = it.second;
      edge curE = {i,b,w};

      e.push_back(curE);
    }
  }
  scanf("%d %d", &factory1, &factory2);
}

bool compare(edge a, edge b){
  return a.weight > b.weight;
}

void init(){
  std::sort(e.begin(), e.end(), compare);
  for(int i=1; i<=n; i++) {
    parent[i] = i;
  }
  ans = 0;
}

// int findRoot(int vertex) {
//   int p = vertex;

//   while(parent[p] != p) {
//     p = parent[p];
//   }

//   return p;
// }

int findRoot(int vertex) {
  return root[vertex];
}

void merge(int v1, int v2) {
  int v1Root = findRoot(v1);
  int v2Root = findRoot(v2);

  if (v1Root < v2Root) {
    // parent[v2Root] = v1Root;
    root[v2Root] = v1Root;
  } else if (v1Root > v2Root) {
    // parent[v1Root] = v2Root;
    root[v2Root] = v1Root;
  }
}

bool isSameRoot(int v1, int v2) {
  int v1Root = findRoot(v1);
  int v2Root = findRoot(v2);

  return v1Root == v2Root;
}

bool isParent(int v1, int v2) {
  int p = v2;

  while(parent[p] != p) {
    p = parent[p];
    if (p == v1) {
      return true;
    }
  }

  return false;
}

lint calcParentDist(int parentVertex, int childVertex) {
  int cur = childVertex;
  lint curMinEdge = INF;

  while(cur != parentVertex) {
    int curMax = 0;
    for(auto &it: graph[cur]) {
      if (it.first == parent[cur] && it.second > curMax) {
        curMax = it.second;
      }
    }
    for(auto &it: graph[parent[cur]]) {
      if (it.first == cur && it.second > curMax) {
        curMax = it.second;
      }
    }
    if (curMinEdge > curMax) {
      curMinEdge = curMax;
    }
    cur = parent[cur];
  }

  return curMinEdge;
}

int findCommonParent(int v1, int v2) {
  int commonParent = 0;

  vector<int> v1Parents;
  vector<int> v2Parents;
  
  int p = v1;

  while(parent[p] != p) {
    v1Parents.push_back(parent[p]);
    p = parent[p];
  }

  p = v2;

  while(parent[p] != p) {
    v2Parents.push_back(parent[p]);
    p = parent[p];
  }

  for (auto &v1Parent: v1Parents) {
    for (auto &v2Parent: v2Parents) {
      if (v1Parent == v2Parent) {
        return v1Parent;
      }
    }
  }

  // 예외상황
  printf("Error");
  exit(-1);
}

void calcDist(int v1, int v2) {
  if (isParent(v1, v2)) {
    ans = calcParentDist(v1, v2);
  } else if (isParent(v2, v1)) {
    ans = calcParentDist(v2, v1);
  } else {
    int commonParent = findCommonParent(v1, v2);
    ans = std::min(calcParentDist(commonParent, v1), calcParentDist(commonParent, v2));
  }
}

void findMST() {
  for(auto &it: e) {
    // 현재 edge를 연결하는 두 vertex를 union find
    merge(it.prev, it.next);
    // 현재 fac1, fac2 가 같은 union인지 파악
    if (isSameRoot(factory1, factory2)) {
      // 같은 union이라면 fac1 -> fac2 로 이동하는 경로에서 가장 작은 edge 사이즈 기록
      calcDist(factory1, factory2);
      return;
    }
  }
}

void process(){
	findMST();
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

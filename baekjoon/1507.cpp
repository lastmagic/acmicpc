#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int> P;
int n,m;
int ans;
bool check[22];
int dist[22][22];
vector<P> graph[22];
void input(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int w;
      scanf("%d", &w);
      graph[i].push_back({-w, j});
    }
  }
}

void process(){
  priority_queue<P> pq;

  for(auto &e: graph[0]){
    pq.push(e);
  }

  check[0] = true;
  while(!pq.empty()){
    auto node = pq.top();
    pq.pop();
    if(check[node.second]) continue;
    check[node.second] = true;
    printf("v = %d w = %d ans = %d\n", node.second,node.first,ans);
    ans += -node.first;
    int next = node.second;
    for(auto &e: graph[next]){
      pq.push(e);
    }
  }
}

void output(){
  printf("%d", ans);
}

int main(void){
  input();
  process();
  output();
}

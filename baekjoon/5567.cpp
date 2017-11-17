#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int n,m;
vector<int> graph[555];
queue<P> q;

bool check[555];
long long ans;
void input(){
  scanf("%d %d", &n,&m);
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}
void bfs(){
  q.push({1,0});
  while(!q.empty()){
    int node = q.front().first;
    int level = q.front().second;
    q.pop();
    if(check[node]) continue;
    check[node] = true;
    if(level==1 || level==2) ans++;

    for(auto &e: graph[node]){
      if(!check[e]){
        q.push({e,level+1});
      }
    }
  }
}

void process(){
  bfs();
}

void output(){
  printf("%lld", ans);
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
int n,m;
int ans;
vector<int> graph[1010];
bool chk[1010];
void input(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
}
void dfs(int node){
  if(chk[node]) return;
  else{
    chk[node] = true;
    for(auto &e: graph[node]){
      dfs(e);
    }
  }
}
void process(){
  for(int i=1; i<=n; i++){
    if(!chk[i]){
      dfs(i);
      ans++;
    }
  }
}

void output(){
  printf("%d", ans);
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

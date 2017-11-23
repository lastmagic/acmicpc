#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#define MAX_SIZE 1010
int n,m,root;
bool chk[MAX_SIZE];
int graph[MAX_SIZE][MAX_SIZE];
using namespace std;
void init(){
  memset(chk, 0, sizeof(chk));
}
void input(){
  scanf("%d %d %d", &n, &m ,&root);
  for(int i=0; i<m; i++){
    int u, v;
    scanf("%d %d", &u,&v);
    graph[u][v] = 1;
    graph[v][u] = 1;
  }
}
void dfs(int node){
  if(chk[node]) return;
  else{
    chk[node] = true;
    printf("%d ", node);
    for(int i=1; i<=n; i++){
      if(graph[node][i] && !chk[i]){
        dfs(i);
      }
    }
  }
}

void bfs(int node){
  queue <int> q;
  q.push(node);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if(chk[now]) continue;
    chk[now] = true;
    printf("%d ", now);
    for(int i=1; i<=n; i++){
      if(graph[now][i] && !chk[i]){
        q.push(i);
      }
    }
  }
}
void process(){
  dfs(root);
  printf("\n");
  init();
  bfs(root);
}

int main(int argc, char const *argv[]) {
  input();
  process();
  return 0;
}

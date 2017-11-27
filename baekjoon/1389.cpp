#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int graph[111][111];
int n,m;
int res;
int ans=INF;
void input(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++){
    int u,v;
    scanf("%d %d", &u, &v);
    graph[u][v] = graph[v][u] = 1;
  }
}
void init(){
  for(int i=0; i<111; i++){
    for(int j=0; j<111; j++){
      graph[i][j]= INF;
    }
  }
}
void process(){
  int ret;
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i==j) continue;
        if(graph[i][j] > graph[i][k]+graph[k][j]){
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }

  for(int i=1; i<=n; i++){
    ret = 0;
    for(int j=1; j<=n; j++){
      if(graph[i][j]!=INF)
        ret += graph[i][j];
    }
    if(ans > ret){
      ans =ret;
      res = i;
    }
  }
}

void output(){
  printf("%d", res);
}
int main(int argc, char const *argv[]) {
  init();
  input();
  process();
  output();
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 987654321
using namespace std;
int n;
int start,dest;
int m;
int dist[111][111];
void init(){
  for(int i=0; i<111; i++){
    for(int j=0; j<111; j++){
      dist[i][j] = INF;
    }
  }
}

void input(){
  scanf("%d", &n);
  scanf("%d %d", &start, &dest);
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    dist[x][y] = dist[y][x] = 1;
  }
}

void process(){
  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

void output(){
  if(dist[start][dest]!=INF)
    printf("%d", dist[start][dest]);
  else
    printf("-1");
}
int main(int argc, char const *argv[]) {
  init();
  input();
  process();
  output();
  return 0;
}

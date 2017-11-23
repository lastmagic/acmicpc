#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int tc;
int m,n,k;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[55][55];
bool chk[55][55];
int ans;

bool inner(int x, int y){
  if((x>=0&&x<m)&&(y>=0&&y<n)) return true;
  else return false;
}
void init(){
  ans =0;
  memset(chk,0,sizeof(chk));
  memset(map,0,sizeof(map));
}
void input(){
  scanf("%d %d %d", &m, &n, &k);
  int u,v;
  for(int i=0; i<k; i++){
    scanf("%d %d", &u, &v);
    map[u][v] = 1;
  }
}

void dfs(int x, int y){
  if(chk[x][y]) return;
  else{
    chk[x][y]= true;
    for(int i=0; i<4; i++){
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(inner(xx,yy)&& map[xx][yy]){
        dfs(xx,yy);
      }
    }
  }
}

void process(){
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(!chk[i][j]&&map[i][j]){
        dfs(i,j);
        ans++;
      }
    }
  }
}

void output(){
  printf("%d\n", ans);
}
int main(int argc, char const *argv[]) {
  scanf("%d", &tc);
  for(int i=0; i<tc; i++){
    init();
    input();
    process();
    output();
  }

  return 0;
}

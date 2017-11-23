#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int m,n,k;
int map[111][111];
bool chk[111][111];
int cnt;
int ans[100100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void input(){
  scanf("%d %d %d", &m,&n,&k);
  for(int i=0; i<k; i++){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d", &x1,&y1,&x2,&y2);
    for(int j=y1; j<y2; j++){
      for(int k=x1; k<x2; k++){
        map[j][k] = 1;
      }
    }
  }
}
bool inner(int x, int y){
  if((x>=0&&x<m)&&(y>=0&&y<n)) return true;
  else return false;
}
void dfs(int x, int y){
  if(chk[x][y]) return;
  else{
    ans[cnt]++;
    chk[x][y]= true;
    for(int i=0; i<4; i++){
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(inner(xx,yy)&&!map[xx][yy]){
        dfs(xx,yy);
      }
    }
  }
}
void process(){
  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(!chk[i][j]&&!map[i][j]){
        dfs(i,j);
        cnt++;
      }
    }
  }
}

void output(){
  sort(ans, ans+cnt);
  printf("%d\n", cnt);
  for(int i=0; i<cnt; i++){
    printf("%d ", ans[i]);
  }
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;
int n;
int map[111][111];
bool chk[111][111];
int ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool inner(int x, int y){
  if((x>=0&&x<n)&&(y>=0&&y<n)) return true;
  else return false;
}
void init(){
  memset(chk, 0, sizeof(chk));
}
void input(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &map[i][j]);
    }
  }
}
void dfs(int x, int y, int h){
  if(chk[x][y]) return;
  else{
    chk[x][y] = true;
    for(int i=0; i<4; i++){
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(inner(xx,yy) && map[xx][yy] > h){
        dfs(xx,yy,h);
      }
    }
  }
}
void process(){
  int cnt;
  for(int h=0; h<=100; h++){
    cnt =0;
    init();
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(map[i][j] > h && !chk[i][j]){
          dfs(i,j,h);
          cnt++;
        }
      }
    }
    ans = max(ans,cnt);
  }
}

void output(){
  if(ans ==0) printf("1");
  else printf("%d", ans);
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

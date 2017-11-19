#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 987654321
typedef pair<int, int> P;
int h,w,n;
int original[1111][1111];
int map[1111][1111];
int chk[1111][1111];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans;
P pos[10];
P start;
queue<P> q;
bool not_x(int x, int y){
  if(map[x][y] >=0) return true;
  else return false;
}
bool inner(int x, int y){
  if((x>=0&&x<h)&&(y>=0&&y<w)) return true;
  else return false;
}
void init(){
  memset(chk, 0 ,sizeof(chk));
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      map[i][j] = original[i][j];
    }
  }
}
bool is_num(char buf){
  if(buf>='0' && buf<='9') return true;
  return false;
}
void input(){
  scanf("%d %d %d", &h, &w, &n);
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      char tmp;
      scanf(" %c", &tmp);
      if(is_num(tmp)){
        pos[tmp-'0'] = {i,j};
        original[i][j]= INF;
      }
      else{
        if(tmp=='S'){
          start.first = i;
          start.second = j;
          original[i][j] = INF;
        }
        else if(tmp=='X'){
          original[i][j] = -1;
        }
        else{
          original[i][j] = INF;
        }
      }
    }
  }
}
void min_path(int cheese){
  init();
  int ret=INF;
  int dest_x = pos[cheese].first;
  int dest_y = pos[cheese].second;
  q.push(start);
  map[start.first][start.second] = 0;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if(chk[x][y]) continue;
    chk[x][y] = true;
    for(int i=0; i<4; i++){
      int xx = x+dx[i], yy= y+dy[i];
      if(!chk[xx][yy] && inner(xx,yy) && not_x(xx,yy)){
        if(map[xx][yy] > map[x][y]+1){
          map[xx][yy] = map[x][y]+1;
          q.push({xx,yy});
          if(dest_x==xx && dest_y ==yy){
            if(ret > map[xx][yy]){
              ret =map[xx][yy];
              start.first = xx;
              start.second = yy;
            }
          }
        }
      }
    }
  }
  ans += ret;
}
void process(){
  for(int i=1; i<=n; i++){
    min_path(i);
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

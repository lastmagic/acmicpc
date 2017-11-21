#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair<int ,int> P;
int ori[111][111]; //original map
int map[111][111];
P start, dest;
int n,m;
int dx[4]= {0,1,0,-1};
int dy[4]= {1,0,-1,0};
int ans;
bool inner(int x, int y){
  if((x>=0&&x<n)&&(y>=0&&y<m)) return true;
  else return false;
}
void input(){
  char buf;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf(" %c", &buf);
      if(buf == 'K'){
        original = 0;
        start.first = i;
        start.second = j;
      }else if(buf == 'H'){
        original = INF;
        dest.first = i;
        dest.second = j;
      }else if(buf == '.'){
        ori[i][j] = INF;
      }else{
        ori[i][j] = -1;
      }
    }
  }
}
void init(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      map[i][j] = ori[i][j];
    }
  }
}
int bfs(){
    queue<P> q;
    q.push({start});
    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i=0; i<4; i++){
        int xx = x+dx[i], yy = y+dy[i];
        if(inner(xx,yy) && map[xx][yy] > map[x][y] +1){
          map[xx][yy] = map[x][y]+1;
          q.push({xx,yy});
        }
      }
    }
    return map[dest.first][dest.second];
}
void process(){
  init();
  ans = bfs();
  if(ans == 1){
    return;
  }else{
    for(int i=1; i<=3; i++){
      while(i개수만큼 쓰는경우){
        if(bfs()==INF){
          ans = i;
          return;
        }
      }
    }
  }
}

void output(){df
  if(ans == 1){
    printf("-1");
  }else{
    printf("%d", ans);
  }
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

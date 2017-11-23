#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int,int> P;
int tc;
int l;
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dist[333][333];
P start,dest;

void init(){
  for(int i=0; i<l; i++){
    for(int j=0; j<l; j++){
      dist[i][j] =INF;
    }
  }
}
void input(){
  scanf("%d", &l);
  scanf("%d %d", &start.first, &start.second);
  scanf("%d %d", &dest.first, &dest.second);
  init();
}
bool inner(int x, int y){
  if((x>=0&&x<l)&&(y>=0&&y<l)) return true;
  else return false;
}
void process(){
  queue <P> q;
  dist[start.first][start.second] = 0;
  q.push(start);
  while(!q.empty()){
    P now = q.front();
    q.pop();
    for(int i=0; i<8; i++){
      int xx= now.first+dx[i];
      int yy= now.second+dy[i];
      if(inner(xx,yy)&&(dist[xx][yy]>dist[now.first][now.second]+1)){
        dist[xx][yy] = dist[now.first][now.second] +1;
        q.push({xx,yy});
      }
    }
  }
}

void output(){
  printf("%d\n",dist[dest.first][dest.second]);
}
int main(int argc, char const *argv[]) {
  scanf("%d", &tc);
  for(int i=0; i<tc; i++){
    input();
    process();
    output();
  }
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int,int> P;
int n,m;
int dist[55][55];
int map[55][55];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ans=-1;
void input(){
	scanf("%d %d", &n, &m);
	char buf;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf(" %c", &buf);
			if(buf=='L'){
				map[i][j] = INF;
			}
			else map[i][j] =-1;
		}
	}
}
bool inner(int x, int y){
	if((x>=0&&x<n)&&(y>=0&&y<m)) return true;
	else return false;
}
void init(){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j] = map[i][j];
		}
	}
}
void bfs(int x, int y){
	queue<P> q;
	q.push({x,y});
	dist[x][y] =0;
	while(!q.empty()){
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int xx = nx+dx[i];
			int yy = ny+dy[i];
			if(inner(xx,yy) && map[xx][yy]==INF && (dist[xx][yy] > dist[nx][ny]+1)){
				dist[xx][yy] = dist[nx][ny]+1;
				if(dist[xx][yy] > ans){
					ans = dist[xx][yy];
				}
				q.push({xx,yy});
			}
		}
	}
}
void process(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]==INF){ //여기서 실수가 있었음, 그냥 map[i][j]로 돌릴경우 inf가 아닌경우에도 돌아가니 조심할것
				init();
				bfs(i,j);
			}
		}
	}
}

void output(){
	printf("%d", ans);
}
int main(void){
	input();
	process();
	output();
	return 0;
}

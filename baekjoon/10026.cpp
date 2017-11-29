#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n;
int map[111][111];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool chk[111][111];
const int RED =1;
const int GRN =-1;
const int BLU =0;
int rgb_ans;
int nomal_ans;
bool inner(int x, int y){
	if((x>=0&&x<n) && (y>=0 &&y<n)) return true;
	else return false;
}
void init(){
	memset(chk, 0 , sizeof(chk));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]==-1) map[i][j]=1;
		}
	}
}
void input(){
	scanf("%d", &n);
	char buf;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %c", &buf);
			if(buf=='R'){
					map[i][j] = 1;
			}
			else if(buf=='G'){
					map[i][j] = -1;
			}
			else if(buf=='B'){
					map[i][j] = 0;
			}
		}
	}
}
void dfs(int x, int y, int col){
	if(chk[x][y]) return;
	chk[x][y] = true;

	for(int i=0; i<4; i++){
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(inner(xx,yy) && !chk[xx][yy] && col == map[xx][yy]){
			dfs(xx,yy,col);
		}
	}
}

void process(){

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!chk[i][j]){
				dfs(i,j, map[i][j]);
				nomal_ans++;
			}
		}
	}

	init();

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!chk[i][j]){
				dfs(i,j, map[i][j]);
				rgb_ans++;
			}
		}
	}
}

void output(){
	printf("%d %d", nomal_ans, rgb_ans);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using std::pair;
using std::vector;
using std::queue;
using P=pair<int,int>;
using lint=long long;
typedef struct{
		int x;
		int y;
		int cnt;
}data;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int NO =-1;
const int INF = 987654321;
int row,col;
int water[55][55];
int hog[55][55];
int hog_depth, water_depth;
bool chk_h[55][55];
bool chk_w[55][55];
queue<data> water_q, hog_q;
P start_w,start_h,dest;
bool isWater(int x ,int y){
	if(water[x][y]>0&&water[x][y]!=INF)	return true;
	else return false;
}
bool inner(int x, int y){
	if((x>=0&&x<row)&&(y>=0&&y<col)) return true;
	else return false;
}
void init(){
	memset(chk_h,0,sizeof(chk_h));
	memset(chk_w,0,sizeof(chk_w));
}
void input(){
	scanf("%d %d", &row, &col);
	char buf;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
				scanf(" %c", &buf);
				if(buf=='.'){
					water[i][j] = hog[i][j] = INF;
				}
				else if(buf=='*'){
					water[i][j] = 0;
					hog[i][j] = NO;
					start_w.first =i;
					start_w.second = j;
				}
				else if(buf=='D'){ //물은 못가지만 고슴도치는 갈 수 있도록 부호처리
					water[i][j] = NO;
					hog[i][j] = INF;
					dest.first = i;
					dest.second = j;
				}
				else if(buf=='S'){
					water[i][j] = INF;
					hog[i][j] = 0;
					start_h.first = i;
					start_h.second = j;
				}
				else if(buf=='X'){
					water[i][j] = hog[i][j] = NO;
				}
		}
	}
}
int find_depth(){
	data tmp;
	tmp.x = start_h.first ; tmp.y = start_h.second; tmp.cnt = 0;
	hog_q.push(tmp);
	while(!hog_q.empty()){
		int x = hog_q.front().x;
		int y = hog_q.front().y;
		int cnt = hog_q.front().cnt;
		hog_q.pop();
		if(chk_h[x][y]) continue;
		chk_h[x][y] = true;
		for(int i=0; i<4; i++){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(inner(xx,yy)&&!chk_h[xx][yy]){
				tmp.x = xx; tmp.y =yy; tmp.cnt = cnt+1;
				if(tmp.cnt > hog_depth)
					hog_depth = tmp.cnt;
				hog_q.push(tmp);
			}
		}
	}
	while(!water_q.empty()){
		int x = water_q.front().x;
		int y = water_q.front().y;
		int cnt = water_q.front().cnt;
		water_q.pop();
		if(chk_w[x][y]) continue;
		chk_w[x][y] = true;
		for(int i=0; i<4; i++){
			int xx = x+dx[i];
			int yy = y+dy[i];
			if(inner(xx,yy)&&!chk_w[xx][yy]){
				tmp.x = xx; tmp.y =yy; tmp.cnt = cnt+1;
				if(tmp.cnt > water_depth)
					water_depth = tmp.cnt;
				water_q.push(tmp);
			}
		}
	}
	return std::max(hog_depth, water_depth);
}
void process(){
	int MAX_LEVEL = find_depth();
	data tmp;
	tmp.x = start_w.first; tmp.y = start_w.second; tmp.cnt = 0;
	water_q.push(tmp);
	tmp.x = start_h.first; tmp.y = start_h.second; tmp.cnt = 0;
	hog_q.push(tmp);

	init();
	int level=0;
	//depth 만큼 움직이도록 로직수정
	for(int i=0; i<MAX_LEVEL; i++){
		while(water_q.front().cnt <=i){
			int x = water_q.front().x;
			int y = water_q.front().y;
			int cnt = water_q.front().cnt;
			water_q.pop();
			if(chk_w[x][y]) continue;
			chk_w[x][y] = true;
			for(int i=0; i<4; i++){
				int xx = x+dx[i];
				int yy = y+dy[i];
				if(inner(xx,yy) && water[xx][yy] > water[x][y]+1){
					water[xx][yy] = water[x][y]+1;
					tmp.x = xx; tmp.y = yy; tmp.cnt = cnt+1;
					water_q.push(tmp);
				}
			}
		}

		while(hog_q.front().cnt <=i){
			int x = hog_q.front().x;
			int y = hog_q.front().y;
			int cnt = hog_q.front().cnt;
			hog_q.pop();
			if(chk_h[x][y]) continue;
			chk_h[x][y] = true;
			for(int i=0; i<4; i++){
				int xx = x+dx[i];
				int yy = y+dy[i];
				if(inner(xx,yy) && !isWater(xx,yy) && hog[xx][yy] > hog[x][y]+1){
					hog[xx][yy] = hog[x][y]+1;
					tmp.x = xx; tmp.y = yy; tmp.cnt = cnt+1;
					hog_q.push(tmp);
				}
			}
		}
	}
}

void output(){
	if(hog[dest.first][dest.second]==INF){
		printf("KAKTUS");
	}
	else
		printf("%d", hog[dest.first][dest.second]);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

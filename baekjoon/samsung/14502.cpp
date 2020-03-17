/*
Samsung 코테 기출문제 풀이시작
https://www.acmicpc.net/problem/14502
2초 512MB
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)
둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.
빈 칸의 개수는 3개 이상이다.
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int map[10][10];
int cur[10][10];
bool chk[10][10];
int res = 0;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void input(){
	scanf("%d %d", &n, &m);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
}

bool inner(int x, int y){
  if((x>=1&&x<=n)&&(y>=1&&y<=m)) return true;
  return false;
}

void init(int x1, int y1, int x2, int y2, int x3 ,int y3){
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cur[i][j] = map[i][j];
			chk[i][j] = false;
		}
	}
	cur[x1][y1] = cur[x2][y2] = cur[x3][y3] = 1;
}

bool isSamePos(int x1, int y1, int x2, int y2) {
	return (x1 == x2) && (y1 == y2);
}

bool isStartable(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (!isSamePos(x1,y1,x2,y2)
	&& !isSamePos(x1,y1,x3,y3)
	&& !isSamePos(x2,y2,x3,y3)
	&& map[x1][y1] == 0
	&& map[x2][y2] == 0
	&& map[x3][y3] == 0);
}

int countArea() {
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (cur[i][j] == 0) cnt ++;
		}
	}

	return cnt;
}

void dfs(int x, int y){
  if(chk[x][y]) return;
  else{
    chk[x][y]= true;
    for(int i=0; i<4; i++){
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(inner(xx,yy)&& cur[xx][yy] == 0){
				cur[xx][yy] = 2;
        dfs(xx,yy);
      }
    }
  }
}

void doDfs() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(!chk[i][j]&&cur[i][j] == 2){
        dfs(i,j);
      }
		}
	}
}

void process(){
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			for (int k=1; k<=n; k++ ) {
				for (int l=1; l<=m; l++) {
					for (int p=1; p<=n; p++) {
						for (int q=1; q<=m; q++) {
							if (isStartable(i,j,k,l,p,q)) {
								// 배열 초기화
								init(i, j, k, l, p, q);
								// step 1 dfs 로 2를 퍼뜨리기
								doDfs();
								// step 2 현재 0의 갯수 세기
								int now = countArea();
								// step 3 res 갱신
								if (now > res) res = now;
							}
						}
					}
				}
			}
		}
	}
}

void output(){
	printf("%d", res);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

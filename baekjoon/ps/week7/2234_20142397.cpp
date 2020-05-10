/*
https://www.acmicpc.net/problem/2234
성곽

대략 위의 그림과 같이 생긴 성곽이 있다. 굵은 선은 벽을 나타내고, 점선은 벽이 없어서 지나다닐 수 있는 통로를 나타낸다. 이러한 형태의 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.
이 성에 있는 방의 개수
가장 넓은 방의 넓이
하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
위의 예에서는 방은 5개고, 가장 큰 방은 9개의 칸으로 이루어져 있으며, 위의 그림에서 화살표가 가리키는 벽을 제거하면 16인 크기의 방을 얻을 수 있다.
성은 m×n(1 ≤ m, n ≤ 50)개의 정사각형 칸으로 이루어진다. 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.

Keyword: Array, DFS, BitMask
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int fortress[51][51]; // 성벽 위치 저장
int visited[51][51]; // 성벽별로 방문 여부 및 방문시 몇번째 방에 포함되어 있는지 저장
int room[51 * 51]; // 방에 포함된 성벽의 개수 저장 (단지번호 붙이기와 동일한 아이디어)
int roomCnt;
int curMaxRoomCnt;
int totalMaxRoomCnt;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
// 아래 값들은 사용하지 않지만 for문에서 0~3의 값을 주는경우 아래와 같은 값(서,북,동,남)을 사용한다고 생각.
const int W = 0;
const int N = 1;
const int E = 2;
const int S = 3;
void input(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      scanf("%d", &fortress[i][j]);
    }
  }
}

// init이 한번쓰이지 않고 성벽을 하나씩 제거하면서 전체탐색을 할때마다 사용하기 초기화용으로 사용
void init(){
  memset(visited, 0, sizeof(visited));
  memset(room, 0, sizeof(room));
  curMaxRoomCnt = 0;
  roomCnt = 0;
}

// 방문하려는 위치가 성벽 안에 있고 벽으로 막고있지 않은지 확인
bool isVisitable(int x, int y, int wallInfo, int direction) {
  int directionWall = 1 << direction;
  return (x >=0 && x < m)
    && (y >=0 && y < n)
    && ((wallInfo & directionWall) != directionWall);
}

void dfs(int x, int y, int val) {
  if (visited[x][y]) return;
  visited[x][y] = val;
  room[val]++;

  if (curMaxRoomCnt < room[val]) {
    curMaxRoomCnt = room[val];
  }

  if (totalMaxRoomCnt < curMaxRoomCnt) {
    totalMaxRoomCnt = curMaxRoomCnt;
  }

  for(int i=0; i<4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];

    if (isVisitable(xx, yy, fortress[x][y], i)) {
      dfs(xx, yy, val);
    }
  }
}

void findDfs() {
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(!visited[i][j]) {
        dfs(i, j, ++roomCnt);
      }
    }
  }
}

void output(){
  printf("%d\n", roomCnt);
  printf("%d\n", curMaxRoomCnt);
}

void process(){
  findDfs();
  output();
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      // 4방면의 벽을 하나씩 지우면서 전체탐색(findDfs) 실행
      for(int k=0; k<4; k++) {
        init();
        int maskedCur = 1 << k;
        bool hasMaskedCur = (fortress[i][j] & maskedCur) == maskedCur;
        fortress[i][j] &= ~maskedCur;
        findDfs();
        // 벽이 원래 있었던 경우에만 복구
        if (hasMaskedCur) {
          fortress[i][j] |= maskedCur;
        }
      }
    }
  }
  printf("%d", totalMaxRoomCnt);
}

int main(void){
	input();
	init();
	process();
	return 0;
}

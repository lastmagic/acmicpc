/*
https://www.acmicpc.net/problem/2580
스도쿠

게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

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
int board[9][9]; // 전체 보드 저장
int row[9]; // 보드 한 행의 값 압축해서 저장 row[i] == 1 1 1 0 1 1 0 1 1 == 475
int col[9]; // 보드 한 열의 값 압축해서 저장
int dia[9]; // 전체 보드 중 sub 보드의 값 압축해서 저장
vector <pii> blank;
bool isFind;
void input(){
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      scanf("%d", &board[i][j]);
      // 입력 후 0인값만 추가로 벡터에 등록
      if (!board[i][j]) {
        blank.push_back({i, j});
      } else {
        // 0이 아닌값의 경우 비트마스크를 위해 압축값 저장
        int maskedCur = 1 << board[i][j];
        int d = (i/3)*3 + (j/3);
        row[i] |= maskedCur;
        col[j] |= maskedCur;
        dia[d] |= maskedCur;
      }
    }
  }
}

void init(){
  // 재귀 도중 프로세스를 exit(0)을 통해 끝낼 수 있지만, 일반 케이스를 고려하여 플래그로 핸들링
  isFind = false;
}

bool isPromise(int x, int y, int val){
  bool res = true;
  int maskedCur = 1 << val;
  // row 확인
  res = res && (row[x] & maskedCur) != maskedCur;
  // col 확인
  res = res && (col[y] & maskedCur) != maskedCur;
  // subBoard 확인
  int d = (x/3)*3 + (y/3);
  res = res && (dia[d] & maskedCur) != maskedCur;

  return res;
}

void output(){
  for(int i=0; i<9; i++) {
    for(int j = 0; j<9; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

void findAns(int index) {
  if (isFind) return;
  if (index >= blank.size()){
    output();
    isFind = true;
    return;
  };
  pii now = blank[index];
  int x = now.first;
  int y = now.second;


  for(int i = 1; i<=9; i++) {
    // 현재 위치 (x,y)에 i값을 넣는게 유망할 경우 i값 셋팅 후 다음 dfs 실행
    if (isPromise(x, y, i)) {
      board[x][y] = i;
      int maskedCur = 1 << board[x][y];
      int d = (x/3)*3 + (y/3);
      row[x] |= maskedCur;
      col[y] |= maskedCur;
      dia[d] |= maskedCur;
      findAns(index + 1);
      board[x][y] = 0;
      row[x] &= ~maskedCur;
      col[y] &= ~maskedCur;
      dia[d] &= ~maskedCur;
    }
  }
}

void process(){
  findAns(0);
}

int main(void){
	input();
	init();
	process();
	return 0;
}

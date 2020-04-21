/*
https://www.acmicpc.net/problem/2667
단지번호붙이기
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

Keyword: Recursion, BFS
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1234567890
using namespace std;
typedef pair<int ,int> P;
queue <P> q;
P temp;
int n;
int arr[1234][1234];
int apt[1234*1234];
int aptCnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool inner(int x, int y) {
  return ((x>=1&&x<=n)&&(y>=1&&y<=n));
}

void input() {
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      scanf("%1d", &arr[i][j]);
    }
  }
}

void bfs(int x, int y) {
  if (!arr[x][y]) return;

  arr[x][y] = 0;
  apt[aptCnt]++;
  for(int i=0; i<4; i++) {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if(inner(xx, yy)&& arr[xx][yy] == 1) {
      bfs(xx,yy);
    }
  }
}

void process() {
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(arr[i][j] == 1) {
        bfs(i,j);
        aptCnt++;
      }
    }
  }
}

void output() {
  printf("%d\n", aptCnt);
  sort(apt, apt+aptCnt);
  for(int i=0; i<aptCnt; i++) {
    printf("%d\n", apt[i]);
  }
}

int main(void)
{
  input();
  process();
  output();
}

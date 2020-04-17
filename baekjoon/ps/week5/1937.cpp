#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

int n, arr[505][505], D[505][505], res;
const int dy[] = {0, -1, 0 ,1};
const int dx[] = {1, 0, -1, 0};

int dp(int x, int y) {
  int &ret =  D[x][y];
  if(ret != -1) return ret;
  ret = 1;
  for(int dir=0; dir<4; ++dir) {
    int curX = x + dx[dir];
    int curY = y + dy[dir];
    if (arr[curX][curY] > arr[x][y]) {
      ret = std::max(ret, dp(curX, curY) + 1);
    }
  }

  return ret;
}

int main() {
  memset(D, -1, sizeof(D));
  scanf("%d", &n);
  for(int x=0; x<n; ++x){
    for(int y=0; y<n; ++y){
      scanf("%d", &arr[x][y]);
    }
  }

  for(int x=0; x<n; ++x){
    for(int y=0; y<n; ++y){
      res= std::max(res, dp(x, y));
    }
  }

  printf("%d", res);
}
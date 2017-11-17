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
int apt_cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int inner(int x, int y)
{
  if((x>=1&&x<=n)&&(y>=1&&y<=n))
    return 1;
  else
    return 0;
}

void input()
{
  scanf("%d", &n);
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      scanf("%1d", &arr[i][j]);
    }
  }
}

void bfs(int x, int y)
{
  arr[x][y] = 0;
  apt[apt_cnt]++;
  for(int i=0; i<4; i++)
  {
    int xx = x + dx[i];
    int yy = y + dy[i];
    if(inner(xx, yy)&& arr[xx][yy] == 1)
    {
      bfs(xx,yy);
    }
  }
}
void process()
{
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if(arr[i][j] == 1)
      {
        bfs(i,j);
        apt_cnt++;
      }
    }
  }
}
void output()
{
  printf("%d\n", apt_cnt);
  sort(apt, apt+apt_cnt);
  for(int i=0; i<apt_cnt; i++)
  {
    printf("%d\n", apt[i]);
  }
}

int main(void)
{
  input();
  process();
  output();
}

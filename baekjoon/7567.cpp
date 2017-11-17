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
int m,n;
int arr[1234][1234];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int flag_zero =1;
int flag_one =1;
int inner(int x, int y)
{
  if((x>=1&&x<=n)&&(y>=1&&y<=m)&&(arr[x][y]>0))
    return 1;
  else
    return 0;
}

void input()
{

  cin >> m >> n;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      scanf(" %d", &arr[i][j]);
      if(arr[i][j]==1)
      {
        arr[i][j] = 1;
        temp = make_pair(i,j);
        q.push(temp);
        flag_one = 0;
      }
      else if(arr[i][j]==0)
      {
        arr[i][j] = INF;
        flag_zero = 0;
      }
      else if(arr[i][j]==-1)
        arr[i][j] = -1;
    }
  }

}

void bfs()
{
  while(!q.empty())
  {
    temp = q.front();
    int x = temp.first;
    int y = temp.second;
    q.pop();
    for(int i=0; i<4; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(inner(xx, yy) && (arr[x][y]+1 < arr[xx][yy]))
      {
        arr[xx][yy] = arr[x][y] +1;
        temp.first = xx;
        temp.second = yy;
        q.push(temp);
      }
    }
  }
}

void output()
{
  int max=-1;
  int flag =0;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      if(arr[i][j]==INF)
      {
        flag = 1;
        break;
      }
      else
      {
        if(max < arr[i][j])
          max = arr[i][j];
      }
    }
  }

  if(flag_zero)
  {
    cout << 0;
    return;
  }

  if(flag == 1)
    cout << -1;
  else
    cout << max-1;

}
int main(void)
{
  input();
  bfs();
  output();
}

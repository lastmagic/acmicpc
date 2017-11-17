#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#define INF 1234567890
using namespace std;
int arr[123][123];
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int inner(int x, int y)
{
  if((x>=1&&x<=n)&&(y>=1&&y<=m))
    return 1;
  else
    return 0;
}
typedef pair<int,int> P;
queue<P> q;
int main(void)
{
  cin >> n >> m;
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=m; j++)
    {
      scanf("%1d", &arr[i][j]);
      arr[i][j] = (arr[i][j]==1)? INF: -1;
    }
  }
  arr[1][1] = 1;
  P temp=make_pair(1,1);
  q.push(temp);
  while(!q.empty())
  {
    temp = q.front();
    int x=temp.first;
    int y=temp.second;
    q.pop();
    for(int i=0; i<4; i++)
    {
      int xx = x+dx[i];
      int yy = y+dy[i];
      if(inner(xx,yy) && (arr[x][y]+1 < arr[xx][yy]))
      {
        arr[xx][yy] = arr[x][y]+1;
        temp.first = xx;
        temp.second = yy;
        q.push(temp);
      }
    }
  }

  cout << arr[n][m];
}

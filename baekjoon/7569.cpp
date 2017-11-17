#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1234567890
using namespace std;
typedef struct point{
    int x;
    int y;
    int z;
}P;
queue <P> q;
P temp;
int m,n,h;
int arr[111][111][111];
int dx[8]={1,0,-1,0,0,0};
int dy[8]={0,1,0,-1,0,0};
int dz[8]={0,0,0,0,1,-1};
int flag_zero =1;
int flag_one =1;
int inner(int x, int y, int z)
{
  if((x>=1&&x<=n)&&(y>=1&&y<=m)&&(z>=1&&z<=h)&&(arr[z][x][y]>0))
    return 1;
  else
    return 0;
}

void input()
{

  cin >> m >> n >> h;
  for(int k=1; k<=h; k++)
  {
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        scanf(" %d", &arr[k][i][j]);
        if(arr[k][i][j]==1)
        {
          arr[k][i][j] = 1;
          temp.z = k; temp.x = i; temp.y =j;
          q.push(temp);
          flag_one = 0;
        }
        else if(arr[k][i][j]==0)
        {
          arr[k][i][j] = INF;
          flag_zero = 0;
        }
        else if(arr[k][i][j]==-1)
          arr[k][i][j] = -1;
      }
    }
  }


}

void bfs()
{
  while(!q.empty())
  {
    temp = q.front();
    int x = temp.x;
    int y = temp.y;
    int z = temp.z;
    q.pop();
    for(int i=0; i<6; i++)
    {
      int xx = x + dx[i];
      int yy = y + dy[i];
      int zz = z + dz[i];
      if(inner(xx, yy, zz) && (arr[z][x][y]+1 < arr[zz][xx][yy]))
      {
        arr[zz][xx][yy] = arr[z][x][y] +1;
        temp.x = xx;
        temp.y = yy;
        temp.z = zz;
        q.push(temp);
      }
    }
  }
}

void output()
{
  int max=-1;
  int flag =0;
  for(int k=1; k<=h; k++)
  {
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if(arr[k][i][j]==INF)
        {
          flag = 1;
          break;
        }
        else
        {
          if(max < arr[k][i][j])
            max = arr[k][i][j];
        }
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

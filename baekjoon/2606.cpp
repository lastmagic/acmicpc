#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1234567890
using namespace std;
vector <int> arr[123];
bool visit[123];
int n, d;
int cnt=0;
void input()
{
  cin >> n >> d;
  for(int i=0; i<d; i++)
  {
    int now, next;
    scanf(" %d %d", &now, &next);
    arr[now].push_back(next);
    arr[next].push_back(now);
  }
}
void bfs(int root)
{
  visit[root] = true;

  if(arr[root].empty())
    return;
  for(vector<int>::iterator it = arr[root].begin(); it!=arr[root].end(); it++)
  {
    if(!visit[*it]&&((*it)<=n))
    {
      bfs(*it);
      cnt++;
    }
  }
}
void output()
{
  cout << cnt;
}
int main()
{
  input();
  bfs(1);
  output();
}

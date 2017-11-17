#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#include<deque>
#define MAXN 33333
#define INF 1234567890
#define SUPER 0
using namespace std;
int n,m;
int dist[MAXN];
void input()
{
  cin >> n;
  int first, end;
  cin >> first >> end;
  dist[1] =first;
  for(int i=2 ;i<=n; i++)
  {
    int cost, before=0;
    cin >> cost;
    while(1)
    {
      cin >> before;
      if(before==-1) break;
      cost += dist[before];
    }
    dist[i] = cost;
  }
}
void output()
{
  for(int i=1; i<=n; i++)
  {
    cout << dist[i] << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);

	input();
  output();

  return 0;
}

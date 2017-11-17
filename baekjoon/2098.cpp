#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <cstdio>
#include <cstring>
#define INF 1234567890
#define MAXN 20
using namespace std;
typedef long long ll;
ll adj[MAXN][MAXN];
ll dp[MAXN][1<<16];
bool check[MAXN];
int n;
ll ans=INF;
int root;
void input(){
  cin >> n;
  for(int i=1; i<=n;i++){
    for(int j=1; j<=n; j++){
      cin >> adj[i][j];
    }
  }
}

void init()
{
  memset(dp ,-1, sizeof(dp));
}
int tsp(int now, int visit)
{
  if(visit == (1<<n)-1)
    return adj[now][1];

  if(dp[now][visit] >= 0)
    return dp[now][visit];

  ll &ret = dp[now][visit];
  ret = INF;

  for(int i=1; i<=n; i++)
  {
    int next = i;

    if((visit &(1<<(next-1)))) continue;
    if(adj[now][next]==0) continue;

    ll temp = adj[now][next] + tsp(next, visit|(1<<(next-1)));
    ret = min(ret,temp);
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  init();
  cout << tsp(1, 1);
  return 0;
}

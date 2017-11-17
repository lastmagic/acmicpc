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
#define MAXN 2222
#define INF 1234567890
#define SUPER 0
using namespace std;
int t;
int n,m,w;
typedef pair<int, int> P;
vector<P> adj[MAXN];
vector<P> super;
bool check[MAXN];
deque<int> cycle;

int dist[MAXN];
void init()
{
  for(int i=0; i<=n; i++)
  {
    adj[i].clear();
    dist[i] =INF;
    check[i] = false;
  }
  n=m=w=0;
}
void input()
{
  cin >> n >> m >> w;
  for(int i=0; i<m; i++)
  {
    int s,e,_t;
    cin >> s>> e>> _t;
    adj[s].push_back(make_pair(e,_t));
    adj[e].push_back(make_pair(s,_t));
  }

  for(int i=0; i<w; i++)
  {
    int s,e,_t;
    cin >> s >> e>> _t;
    adj[s].push_back(make_pair(e,-_t));
  }
  for(int i=1; i<=n; i++)
  {
    adj[0].push_back(make_pair(i,0));
  }
}

bool bellman(int start)
{
  bool fail;
  for(int i=1; i<=n; i++)
  {
    dist[i] = INF;
  }
  dist[start] = 0;

  for(int i=0; i<n; i++)
  {
    fail = false;
    for(int j=0; j<=n; j++)
    {
      for(vector<P>::iterator it = adj[j].begin(); it!=adj[j].end(); it++)
      {
        if(dist[j] !=INF && dist[it->first] > dist[j] + it->second)
        {
          dist[it->first] = dist[j]+it->second;
          fail= true;
        }
      }
    }
  }
  return !fail;
}
void output(bool neg, int start)
{
  if(!neg)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin >> t;
  for(int i=0; i<t; i++)
  {
    input();
    output(bellman(0),0);
    init();
  }

  return 0;
}

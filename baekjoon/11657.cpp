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
int n,m,w;
typedef pair<int, int> P;
vector<P> adj[MAXN];

int dist[MAXN];

void input()
{
  cin >> n >> m;
  for(int i=0; i<m; i++)
  {
    int s,e,_t;
    cin >> s>> e>> _t;
    adj[s].push_back(make_pair(e,_t));
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
    cout << -1;
  else
	{
		for(int i=2; i<=n; i++)
		{
			if(dist[i]!=INF)
				cout << dist[i] <<"\n";
			else
				cout << -1 << "\n";
		}
	}
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);

  input();
  output(bellman(1),1);

  return 0;
}

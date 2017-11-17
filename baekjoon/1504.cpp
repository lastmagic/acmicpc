#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
#define INF 1234567890
using namespace std;
const int MAXN=1111;
int v,e;
int mid[2];
typedef pair<int, int> P;
vector<P> adj[MAXN];
int dist[MAXN];
int parent[MAXN];
void input()
{
  cin >> v>> e;
  for(int i=0; i<e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
  }
  cin >> mid[0] >> mid[1];
}

bool operator <(P a, P b)
{
  return a.second > b.second;
}
void dijk(int start)
{
  parent[start]= start;
  priority_queue<P> pq;
  for(int i=1; i<=v; i++) dist[i] = INF;
  dist[start] = 0;
  pq.push(make_pair(start,0));

  while(!pq.empty())
  {
    int here = pq.top().first;
    int weight = pq.top().second;
    pq.pop();
    if(weight > dist[here]) continue;
    for(vector<P>:: iterator it = adj[here].begin(); it!=adj[here].end(); it++)
    {
      int next = it->first;
      int cost = it->second;
      if(dist[next] > weight+cost)
      {
        parent[next] = here;
        dist[next] = weight+cost;
        pq.push(make_pair(next, dist[next]));
      }
    }
  }

}

void process()
{
  long long ans=0;
  long long ans2=0;

  dijk(1);
  for(int i=0; i<2; i++)
  {
    ans +=dist[mid[i]];
    dijk(mid[i]);
  }
    ans += dist[v];

  dijk(1);
  for(int i=1; i>=0; i--)
  {
    ans2 +=dist[mid[i]];
    dijk(mid[i]);
  }ㅔ

    ans2 += dist[v];

  ans = min(ans,ans2);

  if(ans >= INF)
    cout << -1;
  else
    cout << ans;
}
int main()
{
  ios::sync_with_stdio(false);
  input();
  process();
}

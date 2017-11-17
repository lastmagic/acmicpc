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
const int MAXN=22222;
int v,e,k;
typedef pair<int, int> P;
vector<P> adj[MAXN];
int dist[MAXN];
void input()
{
  cin >> v>> e;
  cin >> k;
  for(int i=0; i<e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v,w));
  }
}

bool operator <(P a, P b)
{
  return a.second > b.second;
}
void dijk(int start)
{
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
        dist[next] = weight+cost;
        pq.push(make_pair(next, dist[next]));
      }
    }

  }

}
void output()
{
  for(int i=1;i<=v; i++)
  {
      if(dist[i]!=INF)
        cout << dist[i] << "\n";
      else
        cout << "INF" << "\n";
  }
}
int main()
{
  ios::sync_with_stdio(false);
  input();
  dijk(k);
  output();
}

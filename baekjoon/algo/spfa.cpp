#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1234567890
#define MAXN 20005
typedef pair<int, int> P;
vector <P> graph[MAXN];
int v,e,k;
int dist[MAXN];
int inQ[MAXN];
void input()
{
  cin >> v>> e>>k;
  for(int i=0; i<e; i++)
  {
    int u,v,w;
    cin >> u >>v>> w;
    graph[u].push_back(make_pair(v,w));
  }
}

void init(int start)
{
  for(int i=1; i<=v; i++)
  {
    dist[i] = INF;
    inQ[i] = 0;
  }
  dist[start] = 0;
}

void spfa(int start)
{
  queue<int> q;
  q.push(start);
  inQ[start] = 1;

  while(!q.empty())
  {
    int now = q.front();
    q.pop();
    inQ[now] =0;
    for(auto &e: graph[now])
    {
      int next = e.first, weight = e.second;
      if(dist[next] > dist[now] + weight)
      {
        dist[next] = dist[now] +weight;
        if(!inQ[next])
        {
          q.push(next);
          inQ[next]=1;
        }
      }
    }
  }
}

void output()
{
  for(int i=1; i<=v; i++)
  {
    if(dist[i] >= INF)
      cout << "INF\n";
    else
      cout << dist[i] << "\n";
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  init(k);
  spfa(k);
  output();
  return 0;
}

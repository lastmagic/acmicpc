#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7fffffffffffffffll
#define MAXN 20005
#define ll long long
typedef pair<ll, ll> P;

vector <P> graph[MAXN];
ll n,start,dest,e;
ll dist[MAXN];
ll inQ[MAXN];
ll money[MAXN];
ll cycle[MAXN];
vector<ll> mid;
ll check[MAXN];
bool flag=false;
bool res=false;
void input(){
  cin >> n>> start>>dest >> e;
  for(int i=0; i<e; i++){
    int u,v,w;
    cin >> u >>v>> w;
    graph[u].push_back(make_pair(v,w));
  }

  for(int i=0;i<n;i++){
    cin >> money[i];
  }
}

void init(int start){
  for(int i=0; i<n; i++){
    dist[i] = -INF;
    inQ[i] = 0;
  }
  dist[start]= money[start];
}

void spfa(int start){
  queue<int> q;
  q.push(start);
  inQ[start] = 1;
  cycle[start]++;
  while(!q.empty()){
    ll now = q.front();
    q.pop();
    inQ[now] =0;
    cycle[now]++;
    if(cycle[now]>n){
      flag =true;
      continue;
    }
    for(auto &e: graph[now]){
      ll next = e.first, weight = e.second;

      if(dist[next] < dist[now] + money[next] - weight){
        dist[next] = dist[now] + money[next] -weight;

        if(!inQ[next]){
          q.push(next);
          inQ[next]=1;
        }
      }
    }
  }
}
void dfs(int s){
  if(s==dest){
    res =true;
    return;
  }
  check[s] = 1;
  for(auto &e: graph[s]){
    ll next = e.first;
    if(!check[next])
      dfs(next);
  }
}
void output(){
  if(dist[dest]==-INF){
    cout <<"gg\n";
  }
  else{
    if(flag ==true){
      for(int i=0; i<n; i++){
        if(cycle[i]>n){
          dfs(i);
        }
      }
      if(res)
        cout << "Gee\n";
      else
        cout << dist[dest];
    }
    else{
      cout << dist[dest];
    }
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  init(start);
  spfa(start);
  output();
  return 0;
}

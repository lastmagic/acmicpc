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
const int MAXN=200001;

int n,m,s;
vector<pair<int,int> > adj[MAXN];
int dist[MAXN];
void dijkstra(int s){
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<=n;i++)dist[i]=INF;
    pq.push(make_pair(0,s));
    dist[s]=0;

    while(!pq.empty()){
        int here=pq.top().second;
        int d=-pq.top().first;
        pq.pop();
        if(d>dist[here])continue;
        for(int i=0;i<adj[here].size();i++){
            int there=adj[here][i].first;
            int cost=adj[here][i].second;
            if(dist[there]>cost+d){
                dist[there]=cost+d;
                pq.push(make_pair(-dist[there],there));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    dijkstra(s);
    for(int i=1;i<=n;i++){
        dist[i]==INF? cout<<"INF"<<"\n" : cout<<dist[i]<<"\n";
    }
    return 0;
}

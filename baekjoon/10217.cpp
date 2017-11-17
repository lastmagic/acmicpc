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
int n,m,k;
typedef pair<int, int> P;
typedef long long ll;
typedef struct{
	int v;
	int c;
	int d;
}T;
vector<T> adj[MAXN];

ll dist[MAXN];
ll money[MAXN];
T tmp;
void init()//테스트케이스만틈 돌리기위해 초기화
{
  for(ll i=0; i<=n; i++)
  {
    adj[i].clear();
    dist[i] =INF;
		money[i] =0;
  }
  n=m=k=0;
}
void input()
{
  cin >> n >> m>> k;
  for(ll i=0; i<k; i++)
  {
    ll u,v,c,d;
    cin >>u>> v>> c>> d;
		tmp.v = v; tmp.c=c; tmp.d=d;
    adj[u].push_back(tmp);
  }
}

void bellman(ll start)
{
  for(ll i=1; i<=n; i++)
  {
    dist[i] = INF;
		money[i] = 0;
  }
  dist[start] = 0;
	money[start] = m;
  for(ll i=0; i<n; i++) //벨만포드를 이용
  {
    for(ll j=1; j<=n; j++)
    {
      for(vector<T>::iterator it = adj[j].begin(); it!=adj[j].end(); it++)
      {
				ll now = j;
				ll next = it->v;
				ll cost_money = it->c;
				ll cost_dist = it->d;
        if(dist[now] !=INF && dist[next] > dist[now] + cost_dist && (money[now]-(cost_money) >= 0))
        {
					//현재노드까지의 거리가 갱신되었고 이노드를 통해서 가는게 다음노드의 거리를 줄일때 --1번조건
					//현재노드에서 남은돈에 티켓값을 지불해도 0보다 클때 --2 번조건
					//동시만족시 갱신
          dist[next] = dist[now]+cost_dist;
					money[next] = money[now]-(cost_money);
        }
      }
    }
  }
}
void output()
{
	//도달 할 수없거나 돈을 더 쓴경우 이동할 수 없다고함.
  if(dist[n]==INF || money[n] <0)
    cout << "Poor KCM\n";
  else
	{
		cout << dist[n] << "\n";
	}
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
	cin >> t;
	for(int i=0; i<t; i++)
	{
		input();
	  bellman(1);
		output();
		init();
	}


  return 0;
}

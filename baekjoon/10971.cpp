#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#define INF 76541234567890
#define MAXN 20
using namespace std;
typedef long long ll;
ll adj[MAXN][MAXN];
ll dp[maxn][1<<16];
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
void dfs(int now, ll dist){
  bool end = true; //dfs로 leaf에 도달했는지 확인
  for(int i=1;i<=n;i++){
    if(check[i]==false){
      end = false;
    }
  }
  if(end){//leaf에서 root로 돌아갈 수 있으면 ans > dist일때 갱신
    if(adj[now][root]!=0){
      dist += adj[now][root];
      if(ans > dist){
        ans = dist;
      }
    }
    return;
  }
  for(int i=1; i<=n; i++){ //dfs를 돌리는부분
    if(i == now) continue; //adj[i][i]인 경우 확인 x
    if(now == 0) root=i; //임의의 0번을 시작으로 돌리기때문에 root잡기
    else if(adj[now][i]==0) continue; //갈 수 없는길
    if(!check[i]){
      check[i] =true;
      dfs(i, dist+adj[now][i]);
      check[i] =false;
    }
  }
}
void process(){
    dfs(0, 0);
}
void output(){
  cout << ans;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  process();
  output();
  return 0;
}

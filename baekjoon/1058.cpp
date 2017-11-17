#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int ,int>P;
int n;
int ans;
bool check[55];
vector<int> graph[55];
void input(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char n_y;
      scanf(" %c", &n_y);
      if(n_y == 'Y')
        graph[i].push_back(j);
    }
  }
}
void init(){
  for(int i=0; i<n; i++){
    check[i] =0;
  }
}

int find_2_friend(int root){
  init();
  int cnt=0;
  queue <P> q;
  q.push({root, 0});
  while(!q.empty()){
    int now = q.front().first;
    int level = q.front().second;
    q.pop();
    if(check[now]) continue;
    check[now] = true;
    if(level == 1 || level == 2) cnt++;
    for(auto &e: graph[now]){
      if(!check[e]){
        q.push({e,level+1});
      }
    }
  }
  return cnt;
}
void process(){
  for(int i=0; i<n; i++){
    ans = max(ans, find_2_friend(i));
  }
}

void output(){
  printf("%d", ans);
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

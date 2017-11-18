#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define TUBE 1
#define GRAPH 0
#define INF 987654321
using namespace std;
typedef pair<int ,int>P;
typedef struct data{
  int node;
  int flag;
  int level;
}data;
vector<int> tube[1111]; //Separate tube , graph
vector<int> graph[100010];
bool check_t[1111];
bool check_g[100010];
int n,k,m;
int ans=INF;
void input(){
  scanf("%d %d %d", &n, &k, &m);
  for(int i=1; i<=m; i++){
    for(int j=0; j<k; j++){
      int num;
      scanf("%d", &num);
      tube[i].push_back(num);
      graph[num].push_back(i);
    }
  }
}
bool chk(int node, int flag){
  if(flag==TUBE){
    if(!check_t[node]){
      check_t[node] =true;
      return false;
    }
    return true;
  }
  else{
    if(!check_g[node]){
      check_g[node] =true;
      return false;
    }
    return true;
  }
}
void min_path(int start){
  queue<data> q;
  data tmp;
  tmp.node = start; tmp.flag = GRAPH; tmp.level =1;//Include start node myself
  q.push(tmp);
  while(!q.empty()){
    int now = q.front().node;
    int flag = q.front().flag;
    int level = q.front().level;
    q.pop();
    if(chk(now, flag)) continue;
    if(flag==TUBE){ //if tube then i will visit grahp, the other same logic.
      for(auto &e: tube[now]){
        tmp.node = e; tmp.flag =  GRAPH; tmp.level=level;
        q.push(tmp);
      }
    }
    else{

      if(now == n){
        if(ans > level){
          ans = level;
        }
      }
      for(auto &e: graph[now]){
        tmp.node = e; tmp.flag = TUBE; tmp.level =level+1;
        q.push(tmp);
      }
    }
  }
}
void process(){
  min_path(1);
}

void output(){
  if(ans==INF){
    printf("-1");
  }
  else{
    printf("%d", ans);
  }

}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

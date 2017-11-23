#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define INF 987654321
#define MAX_SIZE 100100
using namespace std;

int n,k;
int dist[MAX_SIZE];
void input(){
  scanf("%d %d", &n, &k);
}

void init(){
  for(int i=0; i<MAX_SIZE; i++){
    dist[i] = INF;
  }
}
void process(){
  init();
  dist[n] = 0;
  queue <int> q;
  q.push(n);
  while(!q.empty()){
    int now = q.front();
    q.pop();

    if((now+1<=100000) &&(dist[now+1] > dist[now]+1)){
      dist[now+1] = dist[now]+1;
      q.push(now+1);
    }
    if((now-1 >=0) && (dist[now-1] > dist[now]+1)){
      dist[now-1] = dist[now]+1;
      q.push(now-1);
    }
    if(now*2<=100000){
      if(dist[now*2] > dist[now]+1){
        dist[now*2] = dist[now]+1;
        q.push(now*2);
      }
    }
  }
}

void output(){
  printf("%d", dist[k]);
}

int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

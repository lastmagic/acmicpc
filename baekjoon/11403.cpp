#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;
int n;
int graph[111][111];
int reach[111][111];
void input(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &graph[i][j]);
      if(graph[i][j]==1){
        reach[i][j] =1;
      }
      else{
        reach[i][j] = INF;
      }
    }
  }
}

void process(){
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(reach[i][j]==INF&&reach[i][k]==1&&reach[k][j]==1){
          reach[i][j] =1;
        }
      }
    }
  }
}

void output(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(reach[i][j]==1)
        printf("1 ");
      else
        printf("0 ");
    }
    printf("\n");
  }
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

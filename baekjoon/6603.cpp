#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int n;
int arr[20];
int ans[20];
void input(){
  scanf("%d", &n);
  if(n==0) exit(0);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
}
void bfs(int last, int cnt){
  if(cnt == 6){
    for(int i=0; i<cnt; i++){
      printf("%d ", ans[i]);
    }
    printf("\n");
    return ;
  }
  else{
    for(int i=last+1; i<n; i++){
      ans[cnt] = arr[i];
      bfs(i, cnt+1);
    }
  }
}
void process(){
  bfs(-1, 0);
  printf("\n");
}

int main(int argc, char const *argv[]) {
  while(true){
    input();
    process();
  }
  return 0;
}

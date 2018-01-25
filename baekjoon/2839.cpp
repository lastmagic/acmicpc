#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n;
int ans=-1;
void input(){
  scanf("%d", &n);
}

void init(){

}

void process(){
  for(int i=n/5; i>=0; i--){
    int tmp = n-(i*5);
    int cnt = i;
    if(tmp%3==0){
      ans = i+(tmp/3);
      return;
    }
  }
}

void output(){
  printf("%d", ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

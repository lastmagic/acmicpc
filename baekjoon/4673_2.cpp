#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int chk[10001];
int dFunction(int n) {
  int ans = n;
  int remain = n;
  while(remain) {
    ans += remain % 10;
    remain /= 10;
  }

  return ans;
}

void init(){
  for (int i=1; i<=10000; i++) {
    if (dFunction(i) <= 10000) {
      chk[dFunction(i)] = 1;
    }
  }
}

void output(){
  for (int i=1; i<=10000; i++) {
    if (chk[i] != 1) {
      printf("%d\n", i);
    }
  }
}

int main(void){
	init();
	output();
	return 0;
}

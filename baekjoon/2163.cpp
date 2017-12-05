#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int ans;
void input(){
	scanf("%d %d", &n,&m);
}

void process(){
	ans = (n*m)-1;
}

void output(){
	printf("%d", ans);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

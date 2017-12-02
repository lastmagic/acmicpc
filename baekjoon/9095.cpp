#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int tc;
int n;
int dp[20];
void input(){
	scanf("%d", &n);
}

void init(){
	memset(dp, 0, sizeof(dp));
	dp[0] =1;
}
void process(){
	init();
	for(int i=1; i<=n; i++){
		if(i-1 >= 0){
			dp[i] += dp[i-1];
		}
		if(i-2 >= 0){
			dp[i] += dp[i-2];
		}
		if(i-3 >= 0){
			dp[i] += dp[i-3];
		}
	}
}

void output(){
	printf("%d\n", dp[n]);
}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		input();
		process();
		output();
	}

	return 0;
}

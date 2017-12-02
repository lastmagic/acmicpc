#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
lint n;
lint dp[100][2];
lint ans;
void input(){
	scanf("%lld", &n);
}
void init(){
	dp[1][0] = 0;
	dp[1][1] = 1;
}
void process(){
	init();
	for(lint i=2; i<=n; i++){
		dp[i][0] = dp[i-1][1] + dp[i-1][0];
		dp[i][1] = dp[i-1][0];
	}
	ans = dp[n][0]+dp[n][1];
}

void output(){
	printf("%lld", ans);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

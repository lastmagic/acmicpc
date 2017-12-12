#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
lint n;
lint dp[111111][3];
lint ans;
const lint L = 0;
const lint R = 1;
const lint M = 2;
const lint MOD = 9901;

void input(){
	scanf("%lld", &n);
}
void init(){
	dp[0][L] = dp[0][R] = dp[0][M] = 1;
}
void process(){
	init();
	for(lint i=1; i<n; i++){
		dp[i][R] = (dp[i-1][L] + dp[i-1][M])%MOD;
		dp[i][L] = (dp[i-1][R] + dp[i-1][M])%MOD;
		dp[i][M] = (dp[i-1][L] + dp[i-1][R] +dp[i-1][M])%MOD;
	}
}

void output(){
	ans = (dp[n-1][L]+dp[n-1][R]+dp[n-1][M])%MOD;
	printf("%lld", ans);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
const int R = 0;
const int C = 1;
const lint INF = 0x7f7f7f7f7f7f7f7f;
lint n;
lint mul[555][2];
lint dp[555][555];
void input(){
	scanf("%lld", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld", &mul[i][R], &mul[i][C]);
	}
}

void init(){
	memset(dp, 0x7f, sizeof(dp));
}
int find_dp(int s, int e){
	if(dp[s][e]!=INF) return dp[s][e];
	if(s>=e) return dp[s][e]=0;
	else if(e-s==1){
		dp[s][e] = mul[s][R]*mul[s][C]*mul[e][C];
	}
	else{
		for(int i=1; i<=e-s; i++){
			lint tmp=0;
			tmp = find_dp(s,e-i) + find_dp(e-i+1,e);
			tmp += mul[s][R]*mul[e][C]*mul[e-i][C];
			if(dp[s][e] > tmp){
				dp[s][e] = tmp;
			}
		}
	}
	return dp[s][e];
}
void process(){
	dp[1][n] = find_dp(1,n);
}

void output(){
	printf("%lld", dp[1][n]);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

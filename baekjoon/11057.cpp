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
const int MOD=10007;
lint dp[1111][1111];
lint ans;
void input(){
	scanf("%d", &n);
}

void init(){
	for(int i=0; i<10; i++){
		dp[1][i] = 1;
	}
}
void process(){
	init();
	for(int i=2; i<=n; i++){
		for(int j=0; j<10; j++){
			for(int k=j; k<10; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= MOD;
			}
		}
	}

	for(int i=0; i<10; i++){
		ans += dp[n][i];
		ans %= MOD;
	}
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

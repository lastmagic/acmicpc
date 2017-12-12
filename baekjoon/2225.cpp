#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
const lint MOD = 1000000000;
lint n,k;
lint dp[222][222];//dp[i][j] == i라는 수를 j개로 만들 수 있음
void input(){
	scanf("%lld %lld", &n, &k);
}

void init(){
	for(int i=1; i<=k; i++){
		dp[0][i] =1;
	}
}

void process(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=k; j++){
			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
		}
	}
}

void output(){
	printf("%lld", dp[n][k]%MOD);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

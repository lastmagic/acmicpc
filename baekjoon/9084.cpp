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
int m;
int coin[22];
int dp[11111];
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]);
	}
	scanf("%d", &m);
}

void init(){
	memset(dp, 0, sizeof(dp));
	memset(coin, 0, sizeof(coin));
}

void process(){
	for(int i=0; i<n; i++){
		dp[coin[i]]++;
		for(int j=coin[i]; j<=m; j++){
			if(j < coin[i]) continue;
			dp[j] += dp[j-coin[i]];
		}
	}
}

void output(){
	printf("%d\n", dp[m]);
}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc ;i++){
		init();
		input();
		process();
		output();
	}

	return 0;
}

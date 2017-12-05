#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,k;
int coin[111];
lint dp[11111];
void input(){
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%d", &coin[i]);
	}
}
void process(){
	for(int i=0; i<n; i++){
		if(coin[i] >k) continue; //런타임 에러방지, 인풋에서 k를 초과하는 동전이 들어오는 경우가 있음
		dp[coin[i]]++; //coin[i]금액으로 만들수 있는 경우의수 1추가
		for(int j=coin[i]; j<=k; j++){
			if(j < coin[i]) continue;
			dp[j] += dp[j-coin[i]];
		}
	}
}

void output(){
	printf("%lld", dp[k]);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

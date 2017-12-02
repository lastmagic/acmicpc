#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define INF 43210987654321
using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;

lint n;
lint source[100100];
lint dp[100100];
lint ans=-INF;
void input(){
	scanf("%lld", &n);
	for(lint i=0; i<n; i++){
		scanf("%lld", &source[i]);
	}
}

void process(){
	for(lint i=0; i<n; i++){
		dp[i] = std::max(dp[i-1]+source[i], source[i]);
		if(ans < dp[i])
			ans = dp[i];
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

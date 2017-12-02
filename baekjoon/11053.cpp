#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using lint=long long;
lint n;
lint dp[1111];
lint source[1111];
lint ret;
void input(){
	scanf("%lld", &n);
	for(lint i=1; i<=n; i++){
		scanf("%lld", &source[i]);
	}
}

void process(){
	for(lint i=1; i<=n; i++){
		dp[i] = 1;
		for(lint j=1; j<=i; j++){
			if(source[i] > source[j] && (dp[i] < dp[j]+1)){
				dp[i] = dp[j]+1;
			}
			if(ret < dp[i])
				ret = dp[i];
		}
	}
}

void output(){
	printf("%lld", ret);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

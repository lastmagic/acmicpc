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
int source[1111];
lint dp[1111];
void input(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &source[i]);
	}
}

void process(){
	for(int i=1; i<=n; i++){
		dp[i] = source[i];
		for(int j=1; j<i; j++){
			if(dp[i] < dp[i-j]+source[j]){
				dp[i] = dp[i-j]+source[j];
			}
		}
	}
}

void output(){
	printf("%lld", dp[n]);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

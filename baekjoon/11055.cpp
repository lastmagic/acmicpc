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
int dp[1111];
lint ans;
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &source[i]);
	}
}

void process(){
	for(int i=0; i<n ;i++){
		dp[i] =  source[i];
		for(int j=0; j<i; j++){
			if(source[j] < source[i] && dp[i] < dp[j]+source[i]){
				dp[i] = dp[j]+source[i];
			}
		}
	}
	for(int i=0; i<n; i++){
		if(ans < dp[i]){
			ans = dp[i];
		}
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

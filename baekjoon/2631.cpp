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
int source[222];
int dp[222];
int ans;
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &source[i]);
	}
}

void init(){
	memset(dp, 0, sizeof(dp));
	ans = 0;
}

void process(){
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(source[j] < source[i] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
	}
	for(int i=0; i<n; i++){
		if(ans < dp[i])
			ans = dp[i];
	}
}

void output(){
	printf("%d", n-ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

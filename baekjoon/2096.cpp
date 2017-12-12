#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

const int L = 0;
const int M = 1;
const int R = 2;
int n;
int source[100001][3];
int dp[100001][3];
void input(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &source[i][j]);
		}
	}
}

void init(){
	memset(dp, 0, sizeof(dp));
}

void process(int mode){
	init();
	for(int i=1; i<=n; i++){
		if(mode == 0){
			dp[i][L] = std::max(dp[i-1][L], dp[i-1][M])+source[i][L];
			dp[i][M] = std::max(std::max(dp[i-1][L], dp[i-1][R]), dp[i-1][M]) +source[i][M];
			dp[i][R] = std::max(dp[i-1][R], dp[i-1][M])+source[i][R];
		}
		else{
			dp[i][L] = std::min(dp[i-1][L], dp[i-1][M])+source[i][L];
			dp[i][M] = std::min(std::min(dp[i-1][L], dp[i-1][R]), dp[i-1][M]) +source[i][M];
			dp[i][R] = std::min(dp[i-1][R], dp[i-1][M])+source[i][R];
		}
	}
}

void output(int mode){
	if(mode ==0){
		printf("%d ", std::max(std::max(dp[n][L],dp[n][R]), dp[n][M]));
	}
	else{
		printf("%d", std::min(std::min(dp[n][L],dp[n][R]), dp[n][M]));
	}
}

int main(void){
	input();
	for(int i=0; i<2;i++){
		process(i);
		output(i);
	}
	return 0;
}

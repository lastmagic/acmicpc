#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n,m;
lint source[1111][1111];
lint dp[1111][1111];
lint max_3(lint a, lint b, lint c){
	a = (a>b) ? a: b;
	return (a>c) ? a: c;
}
void input(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m; j++){
			scanf("%lld", &source[i][j]);
		}
	}
}

void process(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = max_3(dp[i-1][j], dp[i][j-1],dp[i-1][j-1])+source[i][j];
		}
	}
}

void output(){
	printf("%lld", dp[n][m]);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

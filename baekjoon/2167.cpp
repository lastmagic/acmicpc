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
int dp[333][333];
int source[333][333];
int k;
pii start[11111];
pii end[11111];
void input(){
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d", &source[i][j]);
		}
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d %d %d %d", &start[i].first,&start[i].second,&end[i].first,&end[i].second);
	}
}

void init(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			dp[i][j] = source[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
}
int preprocess(int idx){
	int x1 = start[idx].first;
	int y1 = start[idx].second;
	int x2 = end[idx].first;
	int y2 = end[idx].second;
	return dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
}
void process(){
	for(int i=0; i<k; i++){
		printf("%d\n", preprocess(i));
	}
}

void output(){

}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

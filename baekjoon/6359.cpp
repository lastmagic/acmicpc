#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int tc,n;
bool dp[111];
int ans;
void input(){
	scanf("%d", &n);
}

void init(){
	for(int i=1; i<=n; i++){
		dp[i] = true;
	}
	ans =0;
}

void process(){
	for(int i=2; i<=n; i++){
		for(int j=i; j<=n; j=j+i){
			dp[j] = !dp[j];
		}
	}
}

void output(){
	for(int i=1; i<=n; i++){
		if(dp[i]) ans++;
	}
	printf("%d\n", ans);
}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		input();
		init();
		process();
		output();
	}
	return 0;
}

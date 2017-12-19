#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
const lint INF = 0x7f7f7f7f7f7f7f7f;
int tc;
int k;
int source[555];
lint dp[555][555];

//i부터 j까지 합칠때의 최송비용을 가지고 있음.
void input(){
	scanf("%d", &k);
	for(int i=1; i<=k; i++){
		scanf("%d", &source[i]);
		source[i] += source[i-1];
	}
}

void init(){
	memset(source, 0, sizeof(source));
	memset(dp, 0x7f, sizeof(dp));
}

lint find_min(int s, int e){
	if(s>e) return dp[s][e] = 0;
	if(dp[s][e]!=INF) return dp[s][e];
	if(s==e) {
		dp[s][e] = 0;
	}
	else if(e-s==1){
		dp[s][e] = source[e] - source[s-1];
	}
	else{
		lint tmp=INF;
		lint sum=0;
		dp[s][e] = 0;
		for(int i=1; i<=e-s; i++){
			sum = 0;
			sum += (find_min(s,e-i) + find_min(e-i+1, e));
			if(tmp > sum){
				tmp = sum;
			}
		}
		dp[s][e] += tmp;
		dp[s][e] += (source[e] - source[s-1]);
	}
	return dp[s][e];
}
void process(){
	dp[1][k] = find_min(1,k);
}

void output(){
	printf("%lld\n", dp[1][k]);
}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		init();
		input();
		process();
		output();
	}

	return 0;
}

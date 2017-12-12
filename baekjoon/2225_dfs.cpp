/*시간제한에 걸리는 소스입니다. */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
const lint MOD = 1000000000;
lint n,k;
lint ans;
void input(){
	scanf("%lld %lld", &n, &k);
}

void init(){
	ans =0;
}

void dfs(lint sum, lint cnt){
	if(sum == n && cnt ==k){
		ans++;
		ans %= MOD;
		return;
	}
	else{
		for(int i=0; i<=n; i++){
			if(sum+i >n) break;
			if(sum+i <= n && cnt+1 <= k){
				dfs(sum+i, cnt+1);
			}
		}
	}
}

void process(){
	dfs(0, 0);
}

void output(){
	printf("%lld", ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

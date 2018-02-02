#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using std::pair;
using std::vector;
using std::queue;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int cnt;
queue<int> q;
int ans[5555];
int idx;
void input(){
	scanf("%d %d", &n, &m);
}

void init(){
	cnt = idx = 0;
	for(int i=1; i<=n; i++){
		q.push(i);
	}
}

void process(){
	while(!q.empty()){
		int now = q.front();
		cnt++;
		q.pop();
		if(cnt == m){
			ans[idx++] = now;
			cnt =0;
		}else{
			q.push(now);
		}
	}
}

void output(){
	printf("<");
	for(int i=0; i<n-1; i++){
		printf("%d, ",ans[i]);
	}
	printf("%d>", ans[n-1]);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

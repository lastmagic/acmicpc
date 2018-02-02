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
const int INF = 0x3f3f3f3f;
int tc;
int n,m;
int cnt;
int sort_arr[111];
int idx;
int ans;
queue <pii> q;
void init(){
	q = queue<pii>();
	ans = cnt = idx= 0;
	memset(sort_arr, 0 , sizeof(sort_arr));
}

void input(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		int buf;
		scanf("%d", &buf);
		if(i==m){
			q.push({buf,1});
		}else{
			q.push({buf,0});
		}
		sort_arr[i] =  buf;
	}
	std::sort(sort_arr, sort_arr+n, std::greater<int>());
}

void process(){
	while(!q.empty()){
		int now = q.front().first;
		int flag = q.front().second;
		if(now == sort_arr[idx]){
			q.pop();
			cnt++;
			if(flag) {
				ans = cnt;
				break;
			}
			idx++;
		}else{
			q.pop();
			q.push({now,flag});
		}
	}
}

void output(){
	printf("%d\n", ans);
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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using std::pair;
using std::vector;
using std::deque;
using pii=pair<int,int>;
using lint=long long;
int n,m;
int buf[55];
int idx;
int l_cnt,r_cnt;
int ans;
deque<int> dq;
void input(){
	scanf("%d %d", &n,&m);
	for(int i=0; i<m; i++){
		scanf("%d", &buf[i]);
	}
}

void init(){
	for(int i=1; i<=n; i++){
		dq.push_back(i);
	}
}
int left(){
	int cnt=-1;
	for(auto it=dq.begin(); it!=dq.end(); it++){
		cnt++;
		if(*it==buf[idx]){
			break;
		}
	}
	return cnt;
}

int right(){
	int cnt=0;
	for(auto it=dq.rbegin(); it!=dq.rend(); it++){
		cnt++;
		if(*it==buf[idx]){
			break;
		}
	}
	return cnt;
}
void process(){
	while(!dq.empty()){
		int now = dq.front();
		if(now == buf[idx]){
			idx++;
			dq.pop_front();
			if(idx == m) break;
			continue;
		}
		l_cnt = left();
		r_cnt = right();
		if(l_cnt<r_cnt){
			ans+=l_cnt;
			now = dq.front();
			while(now!=buf[idx]){
				dq.push_back(now);
				dq.pop_front();
				now = dq.front();
			}
		}else{
			ans+=r_cnt;
			now = dq.back();
			while(now!=buf[idx]){
				dq.push_front(now);
				dq.pop_back();
				now = dq.back();
			}
			dq.push_front(now);
			dq.pop_back();
		}
	}
}

void output(){
	printf("%d", ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

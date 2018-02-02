#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
const int INF = 0x3f3f3f3f;
lint n;
lint plus[4444];
lint minus[4444];
lint _min,_max;
lint cnt_max;
double avg_val;
lint mid_val;
lint usual_ans[8888];
lint usual_val;
lint range_val;
void input(){
	lint buf;
	scanf("%lld", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &buf);
		if(buf>=0) {
			plus[buf]++;
		}else{
			minus[-buf]++;
		}
		if(buf > _max) _max = buf;
		if(buf < _min) _min = buf;
	}
}

void init(){
	_min = INF;
	_max = -INF;
	memset(plus, 0, sizeof(plus));
	memset(minus, 0, sizeof(plus));
}
void avg(){
	lint sum=0;
	for(int i=0; i<=4000; i++){
		if(plus[i] !=0) sum+=plus[i]*i;
		if(minus[i] !=0) sum-=minus[i]*i;
	}
	avg_val = (double)sum/n;
}
void mid(){
	lint cnt=0;
	for(int i=4000; i>0; i--){
		if(minus[i]){
			cnt+=minus[i];
		}
		if(cnt>=(n/2)+1){
			mid_val = -i;
			return;
		}
	}
	for(int i=0; i<=4000; i++){
		if(plus[i]){
			cnt+=plus[i];
		}
		if(cnt>=(n/2)+1){
			mid_val = i;
			return;
		}
	}
}
void usual(){
	int cnt=0, max_val=0;
	for(int i=4000; i>0; i--){
		if(minus[i] > max_val){
			cnt = 0;
			usual_ans[cnt++] = -i;
			max_val = minus[i];
		}else if(minus[i] == max_val){
			usual_ans[cnt++] = -i;
		}
	}
	for(int i=0; i<=4000; i++){
		if(plus[i] > max_val){
			cnt = 0;
			usual_ans[cnt++] = i;
			max_val = plus[i];
		}else if(plus[i] == max_val){
			usual_ans[cnt++] = i;
		}
	}
	if(cnt ==1){
		usual_val = usual_ans[0];
	}else{
		usual_val = usual_ans[1];
	}
}
void range(){
	range_val = _max - _min;
}
void process(){
	avg();
	mid();
	usual();
	range();
}

void output(){
	printf("%.0lf\n%lld\n%lld\n%lld", avg_val, mid_val, usual_val, range_val);
}

int main(void){
	init();
	input();
	process();
	output();
	return 0;
}

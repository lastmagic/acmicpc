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
lint min,max;
lint cnt_max;
double avg_val;
lint mid_val;
lint usual_val;
lint range_val;
void input(){
	lint buf;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &buf);
		if(buf>=0) {
			plus[buf]++;
		}else{
			minus[buf]++;
		}
		if(buf > max) max = buf;
		if(buf < min) min = buf;
	}
}

void init(){
	min = INF;
	max = -INF;
	memset(plus, 0, sizeofF(plus));
	memset(minus, 0, sizeofF(plus));
}
void avg(){
	for(int i=0; i<=4000; i++){

	}
}
void mid(){

}
void usual(){
	int first=0,second=0;
	for(int i=0; i<=4000; i++){
		if()
	}
}
void range(){
	range_val = max - mid;

void process(){
	avg();
	mid();
	usual_val();
	ragne();
}

void output(){

}

int main(void){
	init();
	input();
	process();
	output();
	return 0;
}

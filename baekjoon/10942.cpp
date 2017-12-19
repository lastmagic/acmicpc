#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int n;
int source[1000100];
int d[2222][2222];
int m;
void input(){
	scanf("%d", &n);
	for(int i=1; i<=n ;i++){
		scanf("%d", &source[i]);
	}
	scanf("%d", &m);
}

void init(){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			d[i][j] = -1;
		}
	}
}

int chk_palin(int s, int e){
	//log n 수준으로 palin을 판단해야 하는 문제임.
	//메모리제이션으로 d[s][e]는 start  부터 end까지 문자열을 봤을때 palin인지 판단하는 배열임
	//재귀적으로 호출되면서 채우고 한번이라도 갱신되었으면 바로 그값을 이용해서 시간을 효율적으로사용!
	if(d[s][e]!=-1) return d[s][e];
	if(s>e) d[s][e] = false;
	if(s==e) d[s][e] = true;
	else if(e-s==1){
		d[s][e] = (source[s]==source[e]) ? true: false;
	}
	else{
		d[s][e] = (source[s]==source[e]) && chk_palin(s+1,e-1);
	}
	return d[s][e];
}

void process(){
	int ans;
	int s,e;
	for(int i=0; i<m ;i++){
		scanf("%d %d", &s, &e);
		ans = chk_palin(s, e);
		printf("%d\n", ans);
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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int tc;
int n;
lint koong[70];
void input(){
	scanf("%d", &n);
}

void init(){
	koong[0] = koong[1] =1;
	koong[2] = 2;
	koong[3] = 4;
	for(int i=4; i<=67; i++){
		koong[i] = koong[i-1]+koong[i-2]+koong[i-3]+koong[i-4];
	}
}

void process(){

}

void output(){
	printf("%lld\n", koong[n]);
}

int main(void){
	scanf("%d", &tc);
	init();
	for(int i=0; i<tc; i++){
		input();
		process();
		output();
	}

	return 0;
}

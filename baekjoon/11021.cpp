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
int num1, num2;
void input(){
	scanf("%d", &tc);
}

void init(){
}

void process(){
	for (int i=0; i<tc; i++) {
		scanf("%d %d", &num1, &num2);
		printf("Case #%d: %d\n", i+1, num1+num2);
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

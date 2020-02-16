#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int num1,num2;
void input(){
	scanf("%d\n%d", &num1, &num2);
}

void init(){

}

void process(){
	int cur = num2;
	while(cur) {
		printf("%d\n" ,(cur % 10) * num1);
		cur /= 10;
	}
	printf("%d", num1 * num2);
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

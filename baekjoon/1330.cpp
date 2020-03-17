#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int num1, num2;
void input(){
	scanf("%d %d", &num1, &num2);
}

void init(){

}

void process(){
	if (num1 > num2) {
		printf(">");
	} else if(num1 < num2) {
		printf("<");
	} else {
		printf("==");
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

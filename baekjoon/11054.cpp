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
int source[1111];
int inc[1111];
int dec[1111];
int ans;
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &source[i]);
	}
}

void init(){
	ans =0;
}

void process(){
	for(int i=0; i<n; i++){
		inc[i] = 1;
		for(int j=0; j<i; j++){
			if(source[j] < source[i] && inc[i] < inc[j]+1){
				inc[i] =inc[j]+1;
			}
		}
	}

	for(int i=n-1; i>=0; i--){
		dec[i] = 1;
		for(int j=n-1; j>i; j--){
			if(source[j] < source[i] && dec[i] < dec[j]+1){
				dec[i] =dec[j]+1;
			}
		}
	}

	for(int i=0; i<n; i++){
		if(inc[i]+dec[i] > ans){
			ans = inc[i] + dec[i];
		}
	}
	ans = ans-1;
	//앞에서는 증가, 뒤에서는 감소하면서 오기때문에 inc와 dec는 중간에 있는값을 한번씩
	//총 2번세었다. 따라서 1을 빼줘야 원하는 값이된다.
}

void output(){
	printf("%d",  ans);
}

int main(void){
	input();
	init();
	process();
	output();
	return 0;
}

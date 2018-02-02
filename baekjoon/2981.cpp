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
int buf[111];
void input(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &buf[i]);
	}
	std::sort(buf, buf+n);
}

void init(){

}

void process(){
	for(int i=2; i<=buf[n-1]; i++){
		bool flag = true;
		int mod = buf[0]%i;
		for(int j=1; j<n; j++){
			if(buf[j]%i!=mod){
				flag = false;
				break;
			}
		}
		if(flag) printf("%d ", i);
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

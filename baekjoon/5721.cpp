#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
int box[10010][10010];
int n,m;
void input(){
	scanf("%d %d", &n, &m);
	if(n==0 && m==0) exit(0);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%d", &box[i][j]);
		}
	}
}

void init(){

}

void process(){

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

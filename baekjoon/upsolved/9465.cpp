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
int source[3][111111];
void input(){
	scanf("%d", &n);
	memset(source, 0, sizeof(source));
	for(int i=1; i<=2; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &source[i][j]);
		}
	}
}

void process(){

}

void output(){

}

int main(void){
	scanf("%d", &tc);
	for(int i=0; i<tc; i++){
		input();
		process();
		output();
	}

	return 0;
}

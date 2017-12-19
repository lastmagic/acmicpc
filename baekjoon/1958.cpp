#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using std::pair;
using std::vector;
using pii=pair<int,int>;
using lint=long long;
char a[1111];
char b[1111];
int dp[1111][1111];
//dp[i][j] 위는 i까지 아래는 j까지 봤을때 lcs

int len_a;
int len_b;
void input(){
	scanf("%s", a);
	scanf("%s", b);
	len_a = strlen(a);
	len_b = strlen(b);
}

void init(){
	memset(dp, 0 ,sizeof(dp));
}

void process(){
	init();
	for(int i=1; i<=len_a; i++){
		for(int j=1; j<=len_b; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}

void output(){
	printf("%d\n", dp[len_a][len_b]);
}

int main(void){
	input();
	process();
	output();
	return 0;
}

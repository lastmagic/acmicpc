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
int out[1111][1111];
int ans[1111];
int cnt;
//dp[i][j] 위는 i까지 아래는 j까지 봤을때 lcs
const int E = 0;
const int L  =1;
const int D = 2;
const int LD =3;
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
	memset(out, 0 , sizeof(out));
}

void process(){
	init();
	for(int i=1; i<=len_a; i++){
		for(int j=1; j<=len_b; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				out[i][j] = LD;
			}
			else{
				if(dp[i-1][j] > dp[i][j-1]){
					dp[i][j] = dp[i-1][j];
					out[i][j] = D;
				}
				else{
					dp[i][j] = dp[i][j-1];
					out[i][j] = L;
				}
			}
		}
	}
}

void output(){
	printf("%d\n", dp[len_a][len_b]);
	int i = len_a;
	int j = len_b;
	while(out[i][j]){
		if(out[i][j]==LD){
			ans[cnt++] = a[i-1];
			i = i-1;
			j = j-1;
		}else if(out[i][j]==L){
			j = j-1;
		}else if(out[i][j]==D){
			i = i-1;
		}
	}
	for(int i=cnt-1; i>=0; i--){
		printf("%c", ans[i]);
	}
}

int main(void){
	input();
	process();
	output();
	return 0;
}

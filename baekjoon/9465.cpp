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
int source[2][111111]; //2줄에 걸쳐나오는 스티커 값 저장
int dp[2][2][111111];
 /*
 [사용/미사용][줄][칸]
 dp[0][i][j] ==(i,j)에서 본인을 사용하지 않은 최대값,
 dp[1][i][j] == (i,j)에서 본인을 사용한 최대
*/
void input(){
	scanf("%d", &n);
	memset(source, 0, sizeof(source));
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<2; i++){
		for(int j=1; j<=n; j++){
			scanf("%d", &source[i][j]);
		}
	}
}
void init(){
	dp[1][0][1] = source[0][1];
	dp[1][1][1] = source[1][1];
}
void process(){
	init();
	for(int j=2; j<=n; j++){
		for(int i=0; i<2; i++){
			if(i==0){
				dp[0][i][j] = std::max(std::max(dp[0][i][j-1],dp[1][i][j-1]),std::max(dp[0][i+1][j-1],dp[1][i+1][j-1]));
				dp[1][i][j] = std::max(std::max(dp[0][i][j-1], dp[1][i+1][j-1]),dp[0][i+1][j-1])+source[i][j];
			}
			else{
				dp[0][i][j] = std::max(std::max(dp[0][i][j-1],dp[1][i][j-1]),std::max(dp[0][i-1][j-1],dp[1][i-1][j-1]));
				dp[1][i][j] = std::max(std::max(dp[0][i][j-1], dp[1][i+1][j-1]),dp[0][i+1][j-1])+source[i][j];
			}
		}
	}
}

void output(){
	printf("%d\n", std::max(std::max(dp[0][0][n],dp[1][0][n]), std::max(dp[0][1][n], dp[1][1][n])));
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

/*
optimization
3차원 배열에서 2차원 배열로 축소
코드 이해 필요

#include <iostream>
#include <algorithm>
using namespace std;

int narr[2][100001];
int dp[2][100001];
int t, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> narr[i][j];
			}
		}
		dp[0][1] = narr[0][1];
		dp[1][1] = narr[1][1];
		for (int i = 2; i <= n; i++)
		{
			dp[0][i] = max(dp[1][i - 1] + narr[0][i], dp[1][i - 2] + narr[0][i]);
			dp[1][i] = max(dp[0][i - 1] + narr[1][i], dp[0][i - 2] + narr[1][i]);
		}
		cout << max(dp[0][n], dp[1][n]) << "\n";
	}
}
*/

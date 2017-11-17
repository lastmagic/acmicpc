#include <iostream>
#include <cstring>
using namespace std;
long long dp[101][10];
#define DIV_NUM 1000000000
int main(int argc, char const *argv[]) {
  int num;
  long long ans =0;
  cin >> num;
  dp[1][0] = 0;
  for(int i=1; i<10; i++)
  {
    dp[1][i] = 1;
  }
  for(int i=2; i<=num; i++)
  {
    for(int m=0; m<10; m++)
    {
      if(m==0)
      {
        dp[i][m] = dp[i-1][1] % DIV_NUM;
      }
      else if(m==9)
      {
        dp[i][m] = dp[i-1][8] % DIV_NUM;
      }
      else
      {
        dp[i][m] = (dp[i-1][m-1] + dp[i-1][m+1]) % DIV_NUM;
      }
    }
  }
  for(int i=0; i<10; i++)
  {
    ans += dp[num][i] % DIV_NUM;
  }
  cout << ans%DIV_NUM;
  return 0;
}

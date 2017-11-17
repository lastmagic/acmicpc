#include <iostream>
#include <cstring>
using namespace std;
void fibo(int num)
{
  long long *dp = new long long[num+1];
  dp[0] = 0;
  dp[1] = 1;
  for(int i=2; i<=num; i++)
  {
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout << dp[num];
}
int main(int argc, char const *argv[]) {
  int num;
  cin >> num;
  fibo(num);
  return 0;
}

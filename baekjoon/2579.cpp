#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  int *arr;

  cin >> num;
  arr = new int[num+1];
  int **dp = new int*[num+1];
  dp[0] = new int[2];
  for(int i=1; i<num+1; i++)
  {
    cin >> arr[i];
    dp[i] = new int[2];
  }
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = dp[1][1] = arr[1];
  for(int i=2; i <= num ;i++)
  {
    dp[i][0] = dp[i-1][1] + arr[i];
    dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
  }
  cout << max(dp[num][0], dp[num][1]);
  return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
void find_max(int **arr, int **dp, int num)
{
    dp[0][0] = arr[0][0];
    for(int i=1; i<num; i++)
    {
      for(int j=0; j<num; j++)
      {
        if(j==0)
        {
          dp[i][j] = dp[i-1][j] + arr[i][j];
        }
        else
        {
          if(dp[i-1][j-1] <= dp[i-1][j])
          {
            dp[i][j] = dp[i-1][j] + arr[i][j];
          }
          else
          {
            dp[i][j] = dp[i-1][j-1] + arr[i][j];
          }
        }

      }
    }
}
int main(int argc, char const *argv[]) {
  int num,max = -1;
  cin >> num;
  int **arr = new int*[num];
  int **dp = new int*[num];
  for(int i=0; i<num; i++)
  {
    arr[i] = new int[num];
    dp[i] = new int[num];
  }
  for(int i=0; i<num; i++)
  {
    for(int j=0; j<i+1; j++)
    {
      cin >> arr[i][j];
    }
  }
  find_max(arr, dp, num);

  for(int i=0; i<num; i++)
  {
    if(max < dp[num-1][i])
      max = dp[num-1][i];
  }
  cout << max;
  return 0;
}

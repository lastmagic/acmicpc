#include <iostream>
#include <cstring>
using namespace  std;
#define RED 0
#define GREEN 1
#define BLUE 2

void find_min(int **rgb, int **dp, int num)
{
  for(int i=1; i<num; i++)
  {
    for(int j=0; j<3; j++)
    {
      if(j==RED)
      {
        if(dp[BLUE][i-1] <= dp[GREEN][i-1])
        {
          dp[RED][i] = rgb[RED][i] + dp[BLUE][i-1];
        }
        else
        {
          dp[RED][i] = rgb[RED][i] + dp[GREEN][i-1];
        }
      }
      else if(j == GREEN)
      {
        if(dp[BLUE][i-1] <= dp[RED][i-1])
        {
          dp[GREEN][i] = rgb[GREEN][i] + dp[BLUE][i-1];
        }
        else
        {
          dp[GREEN][i] = rgb[GREEN][i] + dp[RED][i-1];
        }
      }
      else if(j == BLUE)
      {
        if(dp[RED][i-1] <= dp[GREEN][i-1])
        {
          dp[BLUE][i] = rgb[BLUE][i] + dp[RED][i-1];
        }
        else
        {
          dp[BLUE][i] = rgb[BLUE][i] + dp[GREEN][i-1];
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  int num, min;
  int *rgb[3];
  int *dp[3];
  cin >> num;
  rgb[RED] = new int[num];
  rgb[GREEN] = new int[num];
  rgb[BLUE] = new int[num];
  dp[RED] = new int[num];
  dp[GREEN] = new int[num];
  dp[BLUE] =new int[num];
  for(int i=0; i<num; i++)
  {
    cin >> rgb[RED][i] >> rgb[GREEN][i] >> rgb[BLUE][i];
  }

  for(int i=0; i<3;i++)
  {
    dp[i][0] = rgb[i][0];
  }
  find_min(rgb,dp,num);

  min = dp[RED][num-1];
  for(int i=0; i<3; i++)
  {
    if(min > dp[i][num-1])
      min = dp[i][num-1];
  }
  cout << min;
  return 0;
}

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
  int num;
  int total;
  int before=-1;
  int cnt=0;
  int *price;
  int *dp;
  cin >> num >> total;
  price = new int[num];
  dp = new int[num];
  for(int i=0; i<num; i++)
  {
    cin >> price[i];
  }
  dp[0] =0;
  for(int i=1; i<=total; i++)
  {
    cout << "i= " << i << "\n";
    for(int j=0; j<num; j++)
    {
      if(i < price[j])
        break;
      dp[i] = dp[i-price[j]] + 1;
      if(i == total && before != dp[total])
      {
        cout << "i = " << i << " before =" << before << " dp[total] = " << dp[total] << " price[] = " << price[j]<<"\n";
        before = dp[total];
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}

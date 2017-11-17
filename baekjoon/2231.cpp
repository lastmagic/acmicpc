#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int len(int num)
{
  int cnt = 0;
  do{
    num = int(num/10);
    cnt++;
  }while(num>0);
  return cnt;
}
int checkPartSum(int num, int partSum)
{
  int sum = num;
  int p = len(num);
  int pow_num =0;
  for(int i=p; i>0; i--)
  {
    pow_num = (int)pow(10,i-1);
    sum += num/pow_num;
    num = num - (int)(num/pow_num)*pow_num;
  }
  if(sum == partSum)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int main(int argc, char const *argv[]) {
  int num;
  cin >> num;
  for(int i=1; i<num; i++)
  {
    if(checkPartSum(i, num))
    {
      cout << i;
      return 0;
    }
  }
  cout << 0;
  return 0;
}

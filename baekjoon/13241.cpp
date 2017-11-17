#include <iostream>
#include <cstring>
using namespace std;
long long gcd(long long num1 ,long long num2)
{
  if(num2 == 0)
    return num1;
  return gcd(num2, num1%num2);
}
long long lcm(long long num1, long long num2)
{
  return num1*num2/gcd(num1, num2);;
}
int main(int argc, char const *argv[]) {
  long long int num1_cnt,num2_cnt;
  cin >> num1_cnt >> num2_cnt;
  if(num1_cnt >= num2_cnt)
  {
    if(num1_cnt % num2_cnt == 0)
    {
      for(int i=0; i<num2_cnt; i++)
        cout << 1;
    }
    else
      cout << 1;
  }
  else
  {
    if(num2_cnt % num1_cnt == 0)
    {
      for(int i=0; i<num1_cnt; i++)
        cout << 1;
    }
    else
      cout << 1;
  }
}

#include <iostream>
#include <cstring>
using namespace std;
int gcd(int num1 ,int num2)
{
  if(num2 == 0)
    return num1;
  return gcd(num1, num1%num2);
}
int main(int argc, char const *argv[]) {
  int test, num1, num2;
  long long mul=0;
  cin >> test;

  for(int i=0; i<test; i++)
  {
    cin >> num1 >> num2;

    if(num1 <= num2)
    {
      mul = num1;
      while(1)
      {
        if((mul % num2) == 0)
        {
          cout << mul << '\n';
          break;
        }
        mul += num1;
      }
    }
    else
    {
      mul = num2;
      while(1)
      {
        if((num2 % num1) == 0)
        {
          cout << mul << '\n';
          break;
        }
        num2 += num2;
      }
    }
  }
  return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long gcd(long long num1 ,long long num2)
{
  if(num2 == 0)
    return num1;
  return gcd(num2, num1%num2);
}
int main(int argc, char const *argv[]) {
  long long a,b,radix;
  cin >> a >> b;
  radix = gcd(a,b);
  if(a % radix == 0 && b % radix == 0)
  {
    while(radix--)
    {
      printf("%d", 1);
    }
  }
  else
    printf("%d", 1);
}

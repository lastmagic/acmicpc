#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int isPrimeNum(int num)
{
  int div=0;
  for(int i=2; i<=num; i++)
  {
    if((num%i)==0)
      div++;
  }
  if(div == 1)
    return 1;
  else
    return 0;
}

int main(int argc, char const *argv[]) {

  int num1, num2,sum=0, min=0;
  cin >> num1 >> num2;
  for(int i=num1; i<=num2; i++)
  {
    if(isPrimeNum(i))
    {
      if(min == 0)
        min = i;
      sum += i;
    }
  }
  if(sum == 0)
  {
    cout << -1;
  }
  else
  {
    cout << sum << "\n";
    cout << min;  
  }

  return 0;
}

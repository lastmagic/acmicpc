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
int main(int argc, char const *argv[])
{
  int n, num, cnt=0;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> num;
    if(isPrimeNum(num))
      cnt++;
  }
  cout << cnt;
  return 0;
}

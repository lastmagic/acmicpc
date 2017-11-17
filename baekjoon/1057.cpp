#include <iostream>
using namespace std;
int diffOne(int num1, int num2)
{
  if(num1 - num2 == 1 || num1 - num2 == -1)
    return 1;
  return 0;
}
int bigger(int num1, int num2)
{
  if(num1 < num2)
    return 1;
  return 0;
}
int main(int argc, char const *argv[]) {
  int num, first, second, cnt=1;
  cin >> num >> first >> second;
  while(1)
  {
    if(diffOne(first, second))
    {
      if(bigger(first, second))
      {
        if(first % 2 == 1 && second % 2 == 0)
        {
          break;
        }
      }
      else
      {
        if(first % 2 == 0 && second % 2 == 1)
        {
          break;
        }
      }
    }
    if(first %2 == 0)
      first = first/2;
    else
      first = first/2 +1;
    if(second %2 == 0)
      second = second/2;
    else
      second = second/2 +1;
    cnt++;
  }

  cout << cnt;
  return 0;
}

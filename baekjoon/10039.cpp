#include <iostream>
using namespace std;
int main(void)
{
  int num, sum=0;
  for(int i=0; i<5; i++)
  {
    cin >> num;
    if(num >40)
      sum += num;
    else
      sum += 40;
  }
  cout << sum/5;
}

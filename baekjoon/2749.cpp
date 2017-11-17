#include <iostream>
using namespace std;
long long divNum = 1000000;
long long period = 1500000;
int main(int argc, char const *argv[]) {

  long long * fibo;
  long long num;
  cin >> num;
  num = num % period;
  fibo = new long long[num];
  fibo[0] =0;
  fibo[1] =1;
  for(int i=2; i<=num;i ++)
  {
    fibo[i] = fibo[i-1] + fibo[i-2];
    fibo[i] %= divNum;
  }
  cout << fibo[num]%divNum;
  return 0;
}

#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int num;
  int stick = 64;
  int cnt =0;
  cin >> num;
  while(1)
  {
    if(num == 0)
      break;
    if(num >= stick)
    {
      cnt++;
      num -= stick;
    }
    stick /= 2;
  }
  cout << cnt;
  return 0;
}

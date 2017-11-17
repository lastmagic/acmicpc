#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int in,out;
  int rest=0;
  int max=0;
  for(int i=0; i<4; i++)
  {
    cin >> out >> in;
    rest = rest + in - out;
    if(rest > max)
      max = rest;
  }
  cout << max;
  return 0;
}

#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  int num;
  int *arr;
  cin >> num;
  arr = new int[num];
  for(int i=0; i<num; i++)
  {
    cin >> arr[i];
  }
  return 0;
}

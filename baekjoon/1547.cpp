#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int num;
  int arr[4] = {-1,1,0,0};
  int first, second,temp = 0;
  cin >> num;
  for(int i=0; i<num ;i++)
  {
    cin >> first >> second;
    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
  }
  for(int i=1; i<4; i++)
  {
    if(arr[i] == 1)
      cout << i;
  }
  return 0;
}

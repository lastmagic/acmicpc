#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
  int arr[9], sum=0;
  for(int i=0; i<9; i++)
  {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr+9);

  for(int i=0; i<8; i++)
  {
    for(int j=i+1; j<9; j++)
    {
        if((sum -(arr[i]+arr[j])) == 100)
        {
          arr[i] = arr[j] = -1;
        }
    }
  }

  for(int i=0; i<9; i++)
  {
    if(arr[i] != -1)
      cout << arr[i] << "\n";
  }
  return 0;
}

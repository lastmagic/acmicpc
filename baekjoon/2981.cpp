#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
void swap(long long *num1, long long *num2)
{
  long long temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
void exchange(long long *arr, int size)
{
  for(int i=0; i< size; i++)
  {
    for(int j=i+1; j<size; j++)
    {
      if(arr[i] > arr[j])
        swap(arr[i], arr[j]);
    }
  }
}
void print(long long *arr, int size)
{
  for(int i=0; i<size; i++)
  {
    cout << arr[i] << "\n";
  }
}
int main(int argc, char const *argv[]) {
  int num;
  long long *arr;
  long long value=0;
  cin >> num;
  arr = new long long[num];
  for(int i=0; i<num; i++)
  {
    cin >> arr[i];
  }
  exchange(arr, num);
  value = arr[num-1] - arr[0];
  for(int i=2; i<=value ; i++)
  {
    if(value % i == 0)
      printf("%d ", i);
  }
  return 0;
}

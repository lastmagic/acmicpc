#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
void swap(char *a, char *b)
{
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void exchangeSort(char *arr, int size)
{
  for(int i=0; i<size; i++)
  {
    for(int j=i+1; j<size; j++)
    {
      if(arr[i] < arr[j])
      {
        swap(&arr[i], &arr[j]);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  long long num;
  cin >> num;
  char arr[11];
  sprintf(arr, "%lld", num);
  exchangeSort(arr, strlen(arr));
  cout << arr;
  return 0;
}

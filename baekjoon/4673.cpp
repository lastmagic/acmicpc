#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int arr[10001];

void selfNum(int *arr, int num)
{
  int sum;
  int pvalue;
  int temp;
  sum = num;
  for(int i=3; i>=0; i--)
  {
    pvalue = pow(10, i);
    sum += num/pvalue;
    num -= (num/pvalue) * pvalue;
  }

   if(sum > 10000)
    return;
   if(arr[sum] == 0)
    return;
   arr[sum] = 0;
   selfNum(arr, sum);
}
int main(int argc, char const *argv[]) {
  memset(arr, -1, sizeof(arr));

  for(int i=1; i<10000; i++)
  {
    selfNum(arr, i);
  }
  for(int i=1; i<10000; i++)
  {
    if(arr[i] == -1)
      printf("%d\n", i);
  }
  return 0;
}

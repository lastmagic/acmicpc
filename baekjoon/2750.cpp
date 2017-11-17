#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

void swap(int *, int *);

void exchangeSort(int *arr, int size);

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void exchangeSort(int *arr, int size)
{
  int i=0,j=0;
  for(i=0; i<size; i++)
  {
    for(j=i+1; j<size; j++)
    {
      if(arr[i]>arr[j])
        swap(arr[i], arr[j]);
    }
  }
}
int main(void)
{
  int *arr;
  int n;
  cin >> n;
  arr = new int[n];
  for(int i=0; i<n; i++)
  {
    cin >> arr[i];
  }

  exchangeSort(arr, n);

  for(int i=0; i<n; i++)
  {
    cout << arr[i] << "\n";
  }
}

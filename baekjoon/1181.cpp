#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
void swap(char *a, char *b)
{
  char temp[51];
  strcpy(temp , a);
  strcpy(a, b);
  strcpy(b, temp);
}
void exchangeSort(char **arr, int size)
{
  for(int i=0; i<size; i++)
  {
    for(int j=i+1; j<size; j++)
    {
      if(strlen(arr[i]) > strlen(arr[j]))
      {
        swap(arr[i], arr[j]);
      }
      else if(strlen(arr[i]) == strlen(arr[j]))
      {
        for(int k=0; k<strlen(arr[i]); k++)
        {
          if(arr[i][k] > arr[j][k])
          {
            swap(arr[i], arr[j]);
            break;
          }
        }
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  int num;
  cin >> num;
  char **arr = new char *[num];
  for(int i=0; i<num; i++)
  {
    arr[i] = new char[51];
    cin >> arr[i];
  }
  exchangeSort(arr, num);
  for(int i=0; i<num; i++)
  {
    if(strcmp(arr[i-1], arr[i]) != 0)
      cout << arr[i] << "\n";
  }
  return 0;
}

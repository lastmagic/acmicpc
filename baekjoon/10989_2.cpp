#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main(void)
{
  int n, temp,i,j;
  int count[10001];
  memset(count, 0x00, sizeof(count));
  cin >>  n;
  for(i=0; i<n; i++)
  {
    cin >> temp;
    count[temp]= count[temp] +1;
  }
  for(i=0; i<10001; i++)
  {
    if(count[i] > 0)
    {
      for(j=0; j<count[i]; j++)
        printf("%d\n", i);
    }
  }
}

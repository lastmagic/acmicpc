#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main(void)
{
  int n;
  char buf[1000];
  int prev, sum=0;
  cin >> n;
  while(getchar()!= '\n');
  for(int i=0; i<n; i++)
  {
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf)-1] = '\0';
    for(int j=0; j<strlen(buf); j++)
    {
      if(buf[j] == 'O')
      {
        if(prev != 0)
        {
          sum = sum + prev +1;
          prev++;
        }
        else
        {
          sum = sum + 1;
          prev++;
        }
      }
      else if(buf[j] =='X')
      {
        prev =0;
      }
    }
    cout << sum <<"\n";
    prev =0;
    sum =0;
  }
}

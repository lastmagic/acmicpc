#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
using namespace std;
int main(void)
{
  int n,length,i,j,k;
  char buf[22];
  cin >> n;
  for(i=0; i<n; i++)
  {
    cin >> length;
    cin >> buf;
    while(buf[j] != '\0')
    {
      for(k=0; k<length; k++)
      {
        cout << buf[j];
      }
      j++;
    }
    j=0;
    strcpy(buf, "");
    cout << '\n';
  }
}

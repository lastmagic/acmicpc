#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdbool.h>
#include <cstdio>
using namespace std;

int main(void)
{
  char arr[2][26] =
  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
,'q','r','s','t','u','v','w','x','y','z',
'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
'Q','R','S','T','U','V','W','X','Y','Z'};
  int check[26];
  char buf;
  int i, max=0, max_cnt=0, index=-1;

  memset(check, 0, sizeof(check));

  while((buf=getchar())!=EOF)
  {
    for(i=0; i<26; i++)
    {
      if((buf == arr[0][i]) || (buf == arr[1][i]))
        check[i]++;
    }
  }
  for(i=0; i<26; i++)
  {
    if(max < check[i])
    {
      max = check[i];
      index= i;
      max_cnt=0;
    }
    else if(max == check[i])
      max_cnt++;
  }
  if(max_cnt ==0)
  {
    cout << arr[1][index];
  }
  else
  {
    cout << "?";
  }
}

#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
int main(void)
{
  char arr[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
,'q','r','s','t','u','v','w','x','y','z'};
  int check[26];
  int i,j;
  for(i=0; i<26; i++)
  {
    check[i] = -1;
  }
  char buf[100];
  cin >> buf;
  for(i=0; i<strlen(buf); i++)
  {
    for(j=0; j<26; j++)
    {
      if((buf[i] == arr[j]) && check[j]==-1)
        check[j] = i;
    }
  }

  for(i=0; i<26; i++)
  {
    cout << check[i] << " ";
  }
}

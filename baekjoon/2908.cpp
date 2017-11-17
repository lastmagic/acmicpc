#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cstdio>
using namespace std;
int make_reverse(int);

int make_reverse(int num)
{
  char buf[50], temp[50];
  int j=0;
  sprintf(buf, "%d",num);
  for(int i=strlen(buf)-1; i>=0; i--)
  {
    temp[j] = buf[i];
    j++;
  }
  return atoi(temp);
}

int main(void)
{
  int num1, num2;
  cin >> num1 >> num2;
  num1 = make_reverse(num1);
  num2 = make_reverse(num2);
  if(num1 > num2)
    cout << num1;
  else
    cout << num2;
}

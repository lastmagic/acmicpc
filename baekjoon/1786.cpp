#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#define N 1000100
char t[N];
char p[N];
int ans[N];
int maxK[N];
int cnt;
int len;
int tlen;
void input()
{
  std::cin.getline(t, N);
  std::cin.getline(p, N);
  tlen = strlen(t);
  len = strlen(p);
}
void find_k()
{
  int i,j=0;
  maxK[0] = -1;
  for(int j=1; j<len; j++)
  {
    i = maxK[j-1];

    while(p[i+1] != p[j] && i>=0)
      i = maxK[i];

    if(p[i+1] == p[j])
      maxK[j] = ++i;
    else
      maxK[j] = -1;
  }
}

void process()
{
  int j =-1;
  find_k();
  for(int i=0; i<tlen; i++)
  {
    while(t[i] != p[j+1] && j>=0)
     j = maxK[j];
     if(t[i] == p[j+1])
     {
       if(j==-1)
       {
         j++;
       }
       else if(j+1 == len-1)
       {
         ans[cnt++] = i - len+2;
         j = maxK[j+1];
       }
       else
       {
        j++;
       }
     }
  }
}

void output()
{
  printf("%d\n", cnt);
  for(int i=0; i<cnt; i++)
  {
    printf("%d ", ans[i]);
  }
}
int main(int argc, char const *argv[]) {

  input();
  process();
  output();
  return 0;
}

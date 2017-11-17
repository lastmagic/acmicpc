#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void)
{
  char buf[101];
  char temp[4];
  char arr[8][4]={
    "c=","c-","dz","d-","lj","nj","s=","z="
  };
  cin >> buf;
  int length = strlen(buf),i=1,j=0,cnt=0;
  cout << "buf=" <<buf <<" length = "<< length<<'\n';
  while(1)
  {
    if(i == length)
      break;
    temp[0] = buf[i-1];
    temp[1] = buf[i];
    temp[2] = '\0';
    temp[3] = '\0';
    cout << "i = "<<i <<" temp = " << temp <<'\n';
    for(j=0; j<8; j++)
    {
      if(strcmp(temp, arr[j])==0)
      {
        if(strcmp(temp, "dz")==0)
        {
          temp[2] = buf[i+1];
          if(strcmp(temp, "dz=")==0)
          {
            i = i+3;
            cnt++;
            continue;
          }
          else
          {
            i++;
            cnt++;
            continue;
          }

        }
        else
        {
          i = i+2;
          cnt++;
          continue;
        }
      }
      else
      {
        i++;
        cnt++;
        continue;
      }
    }
  }
  cout << cnt;
}

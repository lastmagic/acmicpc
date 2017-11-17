#include <iostream>
#include <string>
#define DESENDING 1
#define ASSENDING 0
#define MIXED -1
using namespace std;
int main(void)
{
  int num;
  int prev = -1;
  int flag= MIXED;
  for(int i=0; i<8; i++)
  {
    cin >> num;
    if(i==0)
    {
      if(num ==8)
      {
        flag = DESENDING;
        prev = 8;
      }
      else if(num ==1)
      {
        flag = ASSENDING;
        prev =1;
      }
      else
      {
        break;
      }
    }
    else
    {
      if(flag == DESENDING)
      {
          if(num == prev-1)
            prev =num;
          else
          {
            flag = MIXED;
            break;
          }
      }
      else if(flag == ASSENDING)
      {
          if(num == prev+1)
            prev = num;
          else
          {
            flag = MIXED;
            break;
          }
      }
    }
  }
  if(flag == DESENDING)
    cout << "descending";
  else if(flag == ASSENDING)
    cout << "ascending";
  else if(flag == MIXED)
    cout << "mixed";
}

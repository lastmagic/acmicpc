#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void)
{
  int arr;
  int cnt=0;

  for(int i=0; i<3; i++)
  {
    for(int j=0; j<4; j++)
    {
      cin >> arr;
      if(arr == 0)
      {
        cnt++;
      }
    }
    if(cnt == 0)
    {
      cout << "E" << "\n";
    }
    else if(cnt ==1)
    {
      cout << "A" << "\n";
    }
    else if(cnt ==2)
    {
      cout << "B" << "\n";
    }
    else if(cnt == 3)
    {
      cout << "C" << "\n";
    }
    else if(cnt == 4)
    {
      cout << "D" << "\n";
    }
    else
    {

    }
    cnt =0;
  }
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <stdio.h>
#define ADD 0
#define RMV 1
#define CHK 2
#define TOG 3
#define ALL 4
#define EPT 5

using namespace std;
int m;
int bit;
char buf[8];
int pos;
void input()
{
  scanf("%d", &m);
  for(int i=0; i<m ;i++){
    scanf("%s", &buf);
    int x;
    if(buf[0] == 'a' && buf[1] == 'd'){
      scanf("%d", &x);
      if((bit & (1<<(x-1))) ==0 )
        bit = (bit | (1<<(x-1)));
    }
    else if(buf[0] == 'r'){
      scanf("%d", &x);
      if((bit & (1<<(x-1))) !=0 )
        bit = (bit ^ (1<<(x-1)));
    }
    else if(buf[0] == 'c'){
      scanf("%d", &x);
      if((bit & (1<<(x-1))) !=0 )
        cout << "1\n";
      else
        cout << "0\n";
    }
    else if(buf[0] == 't'){
      scanf("%d", &x);
      if((bit & (1<<(x-1))) !=0 )
        bit = (bit ^ (1<<(x-1)));
      else
        bit = (bit | (1<<(x-1)));
    }
    else if(buf[0] == 'a'){
      bit = 1048575;
    }
    else if(buf[0] == 'e'){
      bit =0;
    }
  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char buf[20];
int len;
int ans;
void input(){
  scanf("%s", buf);
  len = strlen(buf);
}

void process(){
  for(int i=0; i<len; i++){
    if(buf[i]=='A' || buf[i] == 'B' || buf[i] == 'C'){
      ans +=3;
    }else if(buf[i]=='D'||buf[i]=='E'||buf[i]=='F'){
      ans +=4;
    }else if(buf[i]=='G'||buf[i]=='H'||buf[i]=='I'){
      ans +=5;
    }else if(buf[i]=='J'||buf[i]=='K'||buf[i]=='L'){
      ans +=6;
    }else if(buf[i]=='M'||buf[i]=='N'||buf[i]=='O'){
      ans +=7;
    }else if(buf[i]=='P'||buf[i]=='Q'||buf[i]=='R'||buf[i]=='S'){
      ans +=8;
    }else if(buf[i]=='T'||buf[i]=='U'||buf[i]=='V'){
      ans +=9;
    }else if(buf[i]=='W'||buf[i]=='X'||buf[i]=='Y'||buf[i]=='Z'){
      ans +=10;
    }

  }
}

void output(){
  printf("%d", ans);
}
int main(int argc, char const *argv[]) {
  input();
  process();
  output();
  return 0;
}

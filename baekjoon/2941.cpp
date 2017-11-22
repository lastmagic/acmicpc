#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
char buf[110];
int len;
int ans;
void input(){
  scanf("%s", buf);
  len = strlen(buf);
}

void process(){
  int i=0;
  while(buf[i]!='\0'){
    if(buf[i]>='a'&&buf[i]<='z'){
      if(buf[i]=='c'){
        if(buf[i+1]=='='||buf[i+1]=='-'){
          i++;
        }
        ans++;
      }
      else if(buf[i]=='d'){
        if(buf[i+1]=='z'&&buf[i+2]=='='){
          i+=2;
        }else if(buf[i+1]=='-'){
          i++;
        }
        ans++;
      }
      else if(buf[i]=='l'||buf[i]=='n'){
        if(buf[i+1]=='j'){
          i++;
        }
        ans++;
      }
      else if(buf[i]=='s'||buf[i]=='z'){
        if(buf[i+1]=='='){
          i++;
        }
        ans++;
      }
      else{
        ans++;
      }
    }
    i++;
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

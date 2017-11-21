#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX_LEN 1000010
using namespace std;
int pos;
int ans;
char buf[1000010];
void input(){
  fgets(buf, MAX_LEN, stdin);
}
bool now_has_word(){
  bool flag =false;
  if(buf[pos]=='\0'||buf[pos]==10) return flag;
  while(buf[pos]!=' '){
    pos++;
    flag =true;
    if(buf[pos]=='\0'||buf[pos]==EOF) break;
  }
  return flag;
}
void process(){
  while(buf[pos]!='\0'&&buf[pos]!=10){
    while(buf[pos]==' '){
        pos++;
    }
    if(now_has_word()) ans++;
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

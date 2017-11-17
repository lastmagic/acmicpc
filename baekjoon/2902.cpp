#include <iostream>
#include <algorithm>
using namespace std;
char buf[101];
void input()
{
  scanf("%s", buf);
}

void process()
{
  for(int i=0; buf[i]!=NULL; i++)
  {
    if(buf[i] >='A' && buf[i]<='Z')
      printf("%c", buf[i]);
  }
}
int main(int argc, char const *argv[]) {
  input();
  process();
  return 0;
}

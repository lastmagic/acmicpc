#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define TRUE 1
#define FALSE 0
int main(void)
{
  int n,group_word_cnt=0, length=0;
  char buf[102];
  char now_reading_char='\0';
  char arr[26] =
  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
,'q','r','s','t','u','v','w','x','y','z'};
  int check[26];
  memset(check, 0, sizeof(check));
  int flag = TRUE;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    cin >> buf;
    length=strlen(buf);
    for(int j=0; j<length; j++)
    {
      for(int k=0; k<26; k++)
      {
        if(buf[j] == arr[k])
        {
          if(check[k] == 0)
            check[k]++;
          else if(now_reading_char != buf[j])
          {
            flag = FALSE;
          }
        }
      }
      now_reading_char =buf[j];
    }
    if(flag == TRUE)
    {
      group_word_cnt++;
    }

    flag = TRUE;
    memset(check, 0, sizeof(check));
  }

  cout << group_word_cnt;
}

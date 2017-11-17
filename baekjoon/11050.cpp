#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
#include<functional>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<climits>
#include<set>
#include<map>
#include<deque>
using namespace std;
int nCr(int n, int r)
{
  if(n<=1)
    return 1;
  else if(r==0)
    return 1;
  else if(n==r)
    return 1;
  else
    return nCr(n-1,r)+nCr(n-1,r-1);
}
int main(int argc, char const *argv[]) {
  int n,k;
  cin >> n >>k;
  cout << nCr(n,k);
  return 0;
}

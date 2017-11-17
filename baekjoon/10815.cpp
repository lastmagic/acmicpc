#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
using namespace std;
int n,m;
int arr[500100];
priority_queue <int, vector<int>, greater<int> > pq;
void input()
{
  scanf("%d", &n);
  int num;
  for(int i=0; i<n; i++)
  {
    scanf("%d", &num);
    pq.push(num);
  }
  for(int i=0; i<n; i++)
  {
    arr[i] = pq.top();
    pq.pop();
  }
}
void process()
{
  scanf("%d", &m);
  int num;
  for(int i=0; i<m; i++)
  {
    scanf("%d", &num);
    int flag = 0;
    int l=0, r=n-1;
    while(l<=r)
    {
      int mid = (l+r)/2;
      if(arr[mid] == num)
      {
        flag = 1;
        break;
      }
      else if(arr[mid] > num)
      {
        r = mid-1;
      }
      else if(arr[mid] < num)
      {
        l = mid+1;
      }
    }
    if(flag) printf("1 ");
    else printf("0 ");
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  process();
  return 0;
}

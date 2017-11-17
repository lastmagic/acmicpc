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
int n;
priority_queue <int, vector<int>, greater<int> > pq;
void input()
{
  cin >> n;
  int num;
  for(int i=0; i<n; i++)
  {
    cin >>num;
    pq.push(num);
  }
}
void output()
{
  while(!pq.empty())
  {
    cout << pq.top() <<"\n";
    pq.pop();
  }
}
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  input();
  output();
  return 0;
}

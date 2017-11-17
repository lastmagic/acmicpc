#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int n;
vector<int> v;
ll cnt;
ll ans;
ll sum;
void input()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    ll num;
    scanf("%lld", &num);
    v.push_back(num);
  }

  sort(v.begin(), v.end());
}
void process()
{
  ll len = v.size();
  for(int i=0; i<len; i++)
  {
    sum = (len-i) * v[i];
    if(sum > ans)
    {
      ans = sum;
    }
  }
}
void output()
{
  printf("%lld", ans);
}
int main(int argc, char const *argv[]) {

  input();
  process();
  output();
  return 0;
}

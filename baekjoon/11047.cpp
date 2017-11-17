#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> v;
ll n,k;
ll ans;
void input()
{
  scanf("%lld %lld", &n ,&k);
  for(ll i=0; i<n; i++)
  {
    ll num;
    scanf("%lld", &num);
    v.push_back(num);
  }
}

void process()
{
  for(auto i= v.rbegin(); i!=v.rend(); i++)
  {
    ll now = *i;
    if(k/now)
    {
      ans += k/now;
      k = k%now;
    }
    if(!k) break;
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

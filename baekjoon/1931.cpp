#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
using P =pair<ll, ll>;
vector<P> c;
ll n;
ll ans;
ll cur;
void input()
{
  scanf("%lld", &n);
  ll start,end;
  for(int i=0; i<n; i++)
  {
    scanf("%lld %lld", &start, &end);
    c.push_back({end, start});
  }
}

void process()
{
  cur = -1;
  sort(c.begin(), c.end());
  for(int i=0; i<n; i++)
  {
    if(c[i].second >= cur)
    {
      printf("cur = %lld start= %lld end = %lld\n", cur, c[i].second, c[i].first);
      cur = c[i].first;
      ans++;
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

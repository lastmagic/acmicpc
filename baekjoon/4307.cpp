#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int tc, n;
int stick;
vector<int> v;

void input();
void init();
void process();
int min_abs(int ,int);
int max_abs(int ,int);

void input()
{
  scanf("%d", &tc);
  for(int i=0; i<tc; i++)
  {
    scanf("%d %d", &stick,&n);
    for(int j=0; j<n; j++)
    {
      int num;
      scanf("%d", &num);
      v.push_back(num);
    }
    process();
    init();
  }
}
void init()
{
  v.clear();
}
void process()
{
  ll ans_min=0;
  ll ans_max=0;
  sort(v.begin(), v.end());
  for(auto i = v.begin(); i!=v.end(); i++)
  {
    ll now_min = min_abs(*i,stick);
    ll now_max = max_abs(*i,stick);
    if(ans_min < now_min)
      ans_min = now_min;
    if(ans_max < now_max)
      ans_max = now_max;
  }
  printf("%lld %lld\n", ans_min, ans_max);
}

int min_abs(int num, int pivot)
{
  if(num < (pivot-num)) return num;
  else return pivot-num;
}
int max_abs(int num, int pivot)
{
  if(num > (pivot-num)) return num;
  else return pivot-num;
}
int main(int argc, char const *argv[]) {
  input();
  return 0;
}

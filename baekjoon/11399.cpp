#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
vector<int> v;
int n;
ll mid_sum;
ll tot_sum;
void input()
{
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    int num;
    scanf("%d", &num);
    v.push_back(num);
  }

  sort(v.begin(), v.end());
}
void process()
{
  for(auto i = v.begin(); i!=v.end(); i++)
  {
    mid_sum += *i;
    tot_sum += mid_sum;
  }
}
void output()
{
  printf("%lld", tot_sum);
}
int main(int argc, char const *argv[]) {

  input();
  process();
  output();
  return 0;
}

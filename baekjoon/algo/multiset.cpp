#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define INF 0x7fffffffffffffffll
#define MAXN 5000001
#define ll long long
typedef pair<ll, ll> P;
ll n,l;
ll arr[MAXN];
multiset<ll> ms;
void input()
{
  cin >> n >> l;
  for(int i = 0; i<n;i++)
  {
    cin >> arr[i];
  }
}

void init()
{
  for(int i=0; i<l; i++)
  {
    ms.insert(arr[i]);
  }
}

void sliding()
{
  for(int i=1; i<=n-l; i++)
  {

  }
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);

  ms.insert(5);
  ms.insert(5);
  ms.insert(10);
  ms.insert(-100);
  ms.insert(1);
  ms.insert(2);
  ms.find(2);
  cout << *ms.begin();
  return 0;
}

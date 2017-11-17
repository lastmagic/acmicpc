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
#include<cmath>
using namespace std;
int m,n;
void input()
{
	cin >> m >> n;
}
int isSqr(int num)
{
	int root = (int)sqrt(num);
	if(root*root == num)
		return 1;
	else
		return 0;
}
void output()
{
	int flag =0;
	long long _min =1234567890;
	long long sum=0;
	for(int i=m; i<=n;i++)
	{
		if(isSqr(i))
		{
			if(flag ==0)
			{
				flag =1;
				_min = i;
			}
			sum += i;
		}
	}
	if(flag !=0)
	{
		cout << sum <<"\n";
		cout << _min;
	}
	else
		cout << -1;

}
int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
  input();
	output();
  return 0;
}

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

#define INF 1234567890
using namespace std;
int tc;
int n;
void input();
void process();
bool prime(int);
void input()
{
	scanf("%d", &n);
	process();
}
bool prime(int num)
{
	int flag =0;
	for(int i=2; i<=sqrt(num); i++)
	{
		if(num%i == 0) {
			flag++;
			break;
		}
	}
	if(flag) return false;
	else return true;
}
void process()
{
	int diff_min=INF;
	int prev,next;
	int left=3,right=n;
	while(left<=right)
	{
		int mid = (left+right)/2;
		if(mid%2==0) mid = mid-1;
		int i = mid;
		if(prime(i) && prime(n-i))
		{
			if((i <=n-i) && (n-2*i < diff_min))
			{
				left = mid+1;
				diff_min = n-2*i;
				prev = i;
				next = n-i;
			}
			else
			{
				right = mid-1;
			}
		}
		else
		{
			right = right-2;
		}
	}
	printf("%d %d\n", prev, next);
}

int main(int argc, char const *argv[]) {
	scanf("%d", &tc);
	for(int i=0; i<tc; i++)
	{
		input();
	}
	return 0;
}

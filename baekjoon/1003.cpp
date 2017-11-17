#include <iostream>
using namespace std;


void find_fibo(int num, int *dp0, int *dp1);

void find_fibo(int num, int *dp0, int *dp1)
{
	int i = 0;
	for (i = 2; i <= num; i++)
	{
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}
	cout << dp0[num] << " " << dp1[num] << "\n";
}

int main(void)
{
	int n, i, temp;
    int dp0[41];
    int dp1[41];
	dp0[0] = 1;
	dp0[1] = 0;
	dp1[0] = 0;
	dp1[1] = 1;

    cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> temp;
		find_fibo(temp,dp0,dp1);
	}
}

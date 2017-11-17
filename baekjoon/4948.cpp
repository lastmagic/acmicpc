#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXSIZE 1000001
int arr[MAXSIZE];


void eratos(int *arr, int num)
{
	long long j=0;
	for(int i=2; i<=num; i++)
	{
		j=2;
		while(1)
		{
			if(i*j > num)
				break;
			arr[i*j] = 1;
			j++;
		}
	}
}

int countZero(int *arr, int start, int end)
{
  int i, cnt=0;
  for(i=start+1; i<=end; i++)
  {
    if(arr[i] == 0)
      cnt++;
  }
  return cnt;
}
int main(int argc, char const *argv[]) {
  int n,cnt;
  while(1)
  {
    cin >> n;
    if(n == 0)
      break;
    memset(arr, 0, sizeof(arr));
    eratos(arr, 2*n);
    cout << countZero(arr, n, 2*n) << '\n';
  }
  return 0;
}

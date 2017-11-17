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

int main(int argc, char const *argv[]) {

	int num1, num2;
	cin >> num1 >> num2;
	for(int i=0; i<=num2 ;i++)
	{
		arr[i] = 0;
	}
	eratos(arr, num2);
	for(int i=num1 ; i<=num2; i++)
	{
		if(arr[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}

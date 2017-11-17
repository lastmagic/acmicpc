#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <cstring>

using namespace std;

void radixSort(short *, int ,int, int);
void radixSort(short *data, int size, int p, int k)
{
	int *counts;
	short	*temp;
	int index, pval, i, j, n;

	if ((counts = new int[k]) == NULL)
		return;
	if ((temp = new short[size]) == NULL)
		return;
	for (n = 0; n < p; n++)
	{
		for (i = 0; i < k; i++)
			counts[i] = 0;
		pval = (int)pow((double)k, (double)n);

		for (j = 0; j < size; j++)
		{
			index = (int)(data[j] / pval) % k;
			counts[index] = counts[index] + 1;
		}

		for (i = 1; i < k; i++)
		{
			counts[i] = counts[i] + counts[i-1];
		}

		for (j = size - 1; j >= 0; j--)
		{
			index = (int)(data[j] / pval) % k;
			temp[counts[index] - 1] = data[j];
			counts[index] = counts[index] - 1;
		}

		memcpy(data, temp, size * sizeof(int));
	}
}

int main(void)
{
	short *arr;
	int n, max=0,cnt=0;
	char radix[10];
	cin >> n;
	arr = new short[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	sprintf(radix, "%d", max);
	for (int i = 0; i < 10; i++)
	{
		if (radix[i] != '\0')
			cnt++;
		else
			break;
	}

	radixSort(arr, n, cnt, 10);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}

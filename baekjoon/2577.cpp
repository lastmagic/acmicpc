#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(void)
{
	int num1, num2, num3;
	int arr[10];
	memset(arr, 0x00, sizeof(arr));
	char buf[20];
	cin >> num1 >> num2 >> num3;
	long long mul = num1 * num2 * num3;
	sprintf(buf, "%d", mul);
	//ltoa(mul, buf, 10);
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (buf[i] == '\0')
			break;
		if (buf[i] == '0')
			arr[0]++;
		else if (buf[i] == '1')
			arr[1]++;
		else if (buf[i] == '2')
			arr[2]++;
		else if (buf[i] == '3')
			arr[3]++;
		else if (buf[i] == '4')
			arr[4]++;
		else if (buf[i] == '5')
			arr[5]++;
		else if (buf[i] == '6')
			arr[6]++;
		else if (buf[i] == '7')
			arr[7]++;
		else if (buf[i] == '8')
			arr[8]++;
		else if (buf[i] == '9')
			arr[9]++;
	}
	for (i = 0; i < 10; i++)
		cout << arr[i] << "\n";
}

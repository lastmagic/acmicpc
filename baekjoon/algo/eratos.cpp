#include<stdio.h>
int main()
{
	bool p[10000] = {0};
	int i, j, t,n;
	for (i = 2; i < 10000; i++) {
    if (!p[i]) {
      for (j = i*i; j < 10000; j += i) {
        p[j] = true;
      }
    }
  }
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = n / 2; i > 0; i--)
			if (!p[i] && !p[n - i])
			{
				printf("%d %d\n", i, n - i);
				break;
			}
	}
}

#include <bits/stdc++.h>
using namespace std;
int a[101][101] = {}, b[101][101] = {};
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1)
			{
				b[i][j] = 1;
				b[j][n - i + 1] = 1;
				b[n + 1 - i][n + 1 - j] = 1;
				b[n + 1 - j][i] = 1;
				//				printf("%d,%d\n",i,j);
				//				printf("%d,%d\n",n+1-i,j);
				//				printf("%d,%d\n",n+1-j,i);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

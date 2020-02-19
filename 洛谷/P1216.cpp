#include<bits/stdc++.h>
using namespace std;
int a[1001][1001] = { },f[1001][1001] = { };
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			scanf("%d",&a[i][j]);
			f[i][j] = a[i][j];
		}
	}
	for(int i = n-1;i >= 0;i--)
	{
		for(int j = i;j >= 0;j--)
		{
			f[i][j]+=max(f[i+1][j],f[i+1][j+1]);
		}
	}
	printf("%d\n",f[0][0]);
	return 0;
}



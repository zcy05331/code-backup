#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
long long n=100,k;
long long a[1001][1001]= {},ans[1001][1001]= {},tmp[1001][1001]= {};
void ax()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{

			tmp[i][j]=a[i][j];
			a[i][j]=0;

		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				a[i][j]=(a[i][j]+((tmp[i][k]*tmp[k][j]))%mod)%mod;
			}
		}
	}
}
void ansx()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			tmp[i][j]=ans[i][j];
			ans[i][j]=0;
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
			{
				ans[i][j]=(ans[i][j]+((a[i][k]*tmp[k][j]))%mod)%mod;
			}
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%lld",&a[i][j]);
			ans[i][j]=a[i][j];
		}
	}
	for (k--; k; k/=2,ax())
	{
		if (k & 1) ansx();
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%lld ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}


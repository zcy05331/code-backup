#include<bits/stdc++.h>
using namespace std;
int a[101]={};
int f[101][101]={};
int sum[101]={};
int main()
{
	freopen("unite.in","r",stdin);
	freopen("unite.out","w",stdout);
	int n;
	scanf("%d",&n);
	memset(f,0x3f3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		f[i][i]=0;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i;k<=j-1;k++)
			{
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
			}
		}
	}
	printf("%d",f[1][n]);
    return 0;
}

#include<bits/stdc++.h>
#define orz
using namespace std;
int f[31][31]= {},t[31][31]= {};
int a[31]= {};
void dfs(int l,int r)
{
	if(l>r)
		return;
	if(l==r)
	{
		printf("%d ",l);
		return;
	}
	printf("%d ",t[l][r]);
	dfs(l,t[l][r]-1);
	dfs(t[l][r]+1,r);
}
int main()
{
#ifdef orz
	freopen("P1040.in","r",stdin);
	freopen("P1040.out","w",stdout);
#endif


	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
		f[i][i]=a[i];
		f[i][i-1]=1;
	}
	for(int l=2; l<=n; l++)
	{
		for(int i=1; i<=n; i++)
		{
			for(int k=i; k<=i+l-1; k++)
			{
				int j=i+l-1;
				if(f[i][j]<f[i][k-1]*f[k+1][j]+a[k])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+a[k];
					t[i][j]=k;
				}
			}
		}
	}
	printf("%d\n",f[1][n]);
	dfs(1,n);
	return 0;
}


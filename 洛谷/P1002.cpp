#include<bits/stdc++.h>
using namespace std;
long long f[10001][10001]= {},ans[10001][10001];
int main()
{
	int n,m,m1,m2;
	scanf("%d%d%d%d",&n,&m,&m1,&m2);
	ans[0][0]=1;
	f[m1][m2]=f[m1-1][m2-2]=f[m1-1][m2+2]=f[m1+1][m2-2]=f[m1+1][m2+2]=f[m1-2][m2-1]=f[m1-2][m2+1]=f[m1+2][m2-1]=f[m1+2][m2+1]=1;
	//for(int i=0; i<=n; i++)f[i][0]=1;
	//for(int i=0; i<=m; i++)f[0][i]=1;
	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=m; j++)
		{
			//if(f[i][j]==1)continue;
			//if(f[i][j]!=0)continue;
			if(i)
				ans[i][j]+=ans[i-1][j];
			if(j)
				ans[i][j]+=ans[i][j-1];
			ans[i][j]*=!f[i][j];
		}
	}
	printf("%lld\n",ans[n][m]);
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int a[1001][1001]= {};
int f[1000001]= {},mark[1001][1001];
int temp[1001][2];
char s[1001][1001];
long long n,m;
int dfs(int x,int y,int c)
{
	mark[x][y]=c;
	f[c]++;
	if(mark[x+1][y]==0&&a[x][y]+a[x+1][y]==1&&x+1>0&&x+1<=n&&y>0&&y<=n)dfs(x+1,y,c);
	if(mark[x-1][y]==0&&a[x][y]+a[x-1][y]==1&&x-1>0&&x-1<=n&&y>0&&y<=n)dfs(x-1,y,c);
	if(mark[x][y+1]==0&&a[x][y]+a[x][y+1]==1&&x>0&&x<=n&&y+1>0&&y+1<=n)dfs(x,y+1,c);
	if(mark[x][y-1]==0&&a[x][y]+a[x][y-1]==1&&x>0&&x<=n&&y-1>0&&y-1<=n)dfs(x,y-1,c);
	return 0;
}
int main()
{
	int cnt=0,x,y;
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1; j<=n; j++)
		{
			a[i][j]=s[i][j]-'0';
		}
	}

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(!mark[i][j])
			{
				cnt++;
				dfs(i,j,cnt);
			}
		}
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",f[mark[x][y]]);
	}
	return 0;
}



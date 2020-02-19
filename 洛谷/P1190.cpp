#include<bits/stdc++.h>
using namespace std;
int a[10001];
int w[101];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
        int minn=1;
        for(int j=2;j<=m;j++)if(w[j]<w[minn])minn=j;
        w[minn]+=a[i];
	}
	int maxx=-1;
	for(int i=1;i<=m;i++)
	{
        if(maxx<w[i])maxx=w[i];
	}
	printf("%d",maxx);
    return 0;
}

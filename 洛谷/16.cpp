#include<bits/stdc++.h>
using namespace std;
int a[10005]= {},b[10005]= {},g[10005]= {},k[10005]= {};
int n,x,y,ans=-1;
int main()
{

	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
	}
	scanf("%d%d",&x,&y);
	for(int i=0;i<n;i++)
	{
		if((a[i]+g[i]>=x)&&(b[i]+k[i]>=y)&&a[i]<=x&&b[i]<=y)ans=(i+1);
	}
	printf("%d",ans);
	return 0;
}


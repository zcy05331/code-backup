#include<bits/stdc++.h>
using namespace std;
typedef long double lf;
lf dist(long long x1,long long y1,long long z1,long long x2,long long y2,long long z2)
{
	lf dis=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
	return dis;
}
long long x[1001],y[1001],z[1001],f[1001],f1[1001],f2[1001];
long long getf(long long x)
{
	if(x!=f[x])f[x]=getf(f[x]);
	return f[x];
}
int main()
{
	int T;
	scanf("%d",&T);
as:
	while(T--)
	{
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
		memset(f,0,sizeof(f));
		memset(f1,0,sizeof(f));
		memset(f2,0,sizeof(f));
		long long n,h,r,tot1=0,tot2=0;
		scanf("%lld%lld%lld",&n,&h,&r);
		for(int i=1; i<=n; i++)f[i]=i;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
			if(z[i]-r<=0)f1[++tot1]=i;
			if(z[i]+r>=h)f2[++tot2]=i;
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(dist(x[i],y[i],z[i],x[j],y[j],z[j])<=2*r)
				{
					long long fi=getf(i);
					long long fj=getf(j);
					f[fi]=fj;
				}
			}
		}
		//sort(f+1,f+n+1);
		int flag=1;
		for(int i=1; i<=tot1; i++)
		{
			for(int j=1; j<=tot2; j++)
			{
				if(getf(f1[i])==getf(f2[j]))
				{
					flag=0;
					puts("Yes");
					goto as;
					break;
				}
			}
		}

		puts("No");

	}
	return 0;
}



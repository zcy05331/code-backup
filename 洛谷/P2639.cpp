#include<bits/stdc++.h>
using namespace std;
int f[13001]= {},w[10001],c[10001];
int main()
{
	int n,v;
	scanf("%d%d",&v,&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=v; j>=0; j--)
		{
			if(j-c[i]>=0)
				f[j]=max(f[j],f[j-c[i]]+c[i]);
		}
	}
	printf("%d\n",f[v]);
	return 0;
}


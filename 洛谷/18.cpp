#include<bits/stdc++.h>
using namespace std;
int a[1001]={};
int main()
{
	int  n,tmp=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(!a[tmp])ans++;
		a[tmp]++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=1000;i++)
	{
		if(a[i])
		{
			printf("%d ",i);
		}
	}
	return 0;
}


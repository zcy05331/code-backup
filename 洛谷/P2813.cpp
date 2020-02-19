#include<bits/stdc++.h>
using namespace std;
int a[100001]={},b[100001]={};
int main()
{
	int m,n,tmp,ans=0,x=0;
	scanf("%d%d",&m,&n);
	tmp=m;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	} 
	sort(a+0,a+m);
	sort(b+0,b+n);
	if(n<=m)
	{
		puts("0");
		return 0;
	} 
	for(int i=0;i<n;i++)
	{
		if(tmp>0&&b[i]>a[x])
		{
			x++;
			tmp--;
		}
		else if(tmp>0&&b[i]<=a[x])
		{
			ans+=b[i];
		}
		else if(tmp==0)
		{
			ans+=b[i];
		}
		
	}
	if(tmp!=0)
	{
		puts("0");
		return 0;
	}
	else 
	{
		printf("%d",ans);
	}
	return 0;
}


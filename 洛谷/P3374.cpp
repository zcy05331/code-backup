#include<bits/stdc++.h>
using namespace std;
int s[500001],a[500001];
int n,m;
int lowbit(int x)
{
	return (x&(-x));
}
int getsum (int k)
{
	int sum=0;
	while(k>0)
	{
		sum+=s[k];
		k-=lowbit(k);
	}
	return sum;
}
int modify(int x,int delta)
{
	while(x<=n)
	{
		s[x]+=delta;
		x+=lowbit(x);	
	}
}
int main()
{
	int tmp,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		modify(i,a[i]);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&tmp,&x,&y);
		if(tmp==1)
		{
			modify(x,y);
		}
		else 
		{
			printf("%d\n",getsum(y)-getsum(x-1));
		}
	}
	return 0;
}


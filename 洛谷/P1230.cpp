#include<bits/stdc++.h>
using namespace std;
struct game
{
	int time,w;
} a[501];
int cmp(const game &a,const game &b)
{
	if(a.w!=b.w)return a.w>b.w;
	return a.time<b.time;
}
int b[501];
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i].time);
	}
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i].w);
	}
	sort(a+0,a+n,cmp);
	for(int i=0; i<n; i++)
	{
		int flag=0;
		for(int j=a[i].time-1; j>=0; j--)
		{
			if(!b[j])
			{
				b[j]=1;  
				flag=7;
				break;
			}
		}
		if(flag!=7) m-=a[i].w;
	}
	printf("%d",m);
	return 0;
}


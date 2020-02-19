#include<bits/stdc++.h>
using namespace std;
int f[100001],n,m;
int init()
{
	for(int i=0; i<n; i++)
	{
		f[i]=i;
	}
}
int find(int v)
{
	if(f[v]==v)
	{
		return v;
	}
	else
	{
		f[v]=find(f[v]);
		return f[v];
	}
}
int merge(int a,int b)
{
	int t1=find(a),t2=find(b);
	if(t1==t2)return 0;
	else
	{
		f[t2]=t1;
	}
	return 0;
}
int main()
{
	int z,x,y,t1=0,t2=0;
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m ;i++)
	{
		scanf("%d%d%d",&z,&x,&y);
		if(z==1)
		{
			merge(x,y);
		}
		else
		{
			t1=find(x);
			t2=find(y);
			if(t1==t2)
			{
				puts("Y");
			}
			else
			{
				puts("N");
			}
		}
	}
	return 0;
}


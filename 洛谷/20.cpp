#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
struct man
{
	int n;
	int w;
	int d;
	int c;
}a[20001];
int e[10]={};
int cmp(const man &a,const man &b)
{
	if(a.w!=b.w)return a.w>b.w;
	return a.n<b.n;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<10;i++)
	{
		scanf("%d",&e[i]);
	}
	for(int i=0;i<n;i++)
	{
		a[i].n=i+1;
		scanf("%d",&a[i].w);
	}
	sort(a+0,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		a[i].d=(i+1);
		a[i].c=(a[i].d-1)%10+1;
		a[i].w+=e[a[i].c-1];
	}
	sort(a+0,a+n,cmp);
	for(int i=0;i<k;i++)
	{
		printf("%d ",a[i].n);
	}
	return 0;
}


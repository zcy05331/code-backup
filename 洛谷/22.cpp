#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
int s[1001]={};
struct water 
{
	int i;
	int t;
}a[10001]={};
int cmp(const water &a,const water &b)
{
	if(a.t!=b.t)return a.t<b.t;
	return a.i<b.i;
}
int main()
{
	int n; 
	double ans=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i].t);
		a[i].i=i;
	}
	sort(a+0,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		ans+=a[i].t*(n-i-1);
		printf("%d ",a[i].i+1);
	}
	printf("\n%.2f",ans/n);
	return 0;
}


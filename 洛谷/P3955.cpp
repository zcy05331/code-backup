#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
#define R register
using namespace std;
int req[1001],book[1001],len[1001];
int n,q;
int slove(int l,int r)
{
	for(int i=0; i<n; i++)
	{
		if(book[i]%int(pow(10,l))==r)return book[i];
	}
	return -1;
}
int main()
{

	scanf("%d%d",&n,&q);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&book[i]);
	}
	sort(book+0,book+n);
	for(int i=0; i<q; i++)
	{
		scanf("%d%d",&len[i],&req[i]);
	
	}
	for(int i=0;i<q;i++)
	{
		printf("%d\n",slove(len[i],req[i]));
	}
	return 0;
}


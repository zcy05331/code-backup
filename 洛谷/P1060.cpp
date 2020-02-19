#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int w[26]={},v[26]={},c[26]={};
int f[26][30001]={};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&w[i],&v[i]);
		c[i]=w[i]*v[i];
	}
	for(int i=0;i<m;i++)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(v[i]<=j+1)f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+c[i]);
			else  f[i][j]=f[i-1][j];
		}
	}
	printf("%d",f[m][n]);
	return 0;
}


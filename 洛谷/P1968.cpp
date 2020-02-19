#include<bits/stdc++.h>
using namespace std;
double f[101][2]={};
int main()
{
	int x=0,n,a;
	scanf("%d",&n);
	scanf("%d",&a);
	f[0][0]=a;
	f[0][1]=100;
	while(++x<n)
	{
		scanf("%d",&a);
		f[x][0]=max(f[x-1][0],f[x-1][1]*a/100.0);
		f[x][1]=max(f[x-1][1],f[x-1][0]*100.0/a);
	} 
	printf("%0.2f",max(f[n-1][1],f[n-1][0]*100.0/a));
	return 0;
}


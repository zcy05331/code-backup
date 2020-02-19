#include<bits/stdc++.h>
using namespace std;
int a[3001]={},s[3001]={};
int main()
{
	int n,m,maxx=300001;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=m-1;i<n;i++)
	{
		if(s[i]-s[i-m]<maxx)maxx=s[i]-s[i-m];
	}
	printf("%d",maxx);
	return 0;
}


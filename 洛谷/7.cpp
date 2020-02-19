#include<bits/stdc++.h>
using namespace std;
int a[100]={};
int main()
{
	int n,ans=0;
	for(int i=0;i<10;i++)cin>>a[i];
	scanf("%d",&n);
	for(int i=0;i<10;i++)
	{
		if(n+30>=a[i])ans++;
	}
	printf("%d",ans);
	return 0;
}


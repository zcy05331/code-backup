#include<bits/stdc++.h>
using namespace std;
char a[100]={};
int main()
{
	int n,x,ans=0;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
	{
		itoa(i,a,10);
		int len=strlen(a);
		for(int j=0;j<len;j++)
		{
			if(a[j]-'0'==x)ans++;
		}
	}
	printf("%d",ans);
	return 0;
}


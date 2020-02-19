#include<bits/stdc++.h>
using namespace std;
int a[10000001]={};
int main()
{
	int n,tmp=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>a[i-1])tmp++;
		else tmp=1;
		if(tmp>=ans)ans=tmp; 
	}
	printf("%d",ans);
	return 0;
}


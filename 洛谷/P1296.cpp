#include<bits/stdc++.h>
using namespace std;
int a[1000001]  ;
int main()
{
	int n;
	int d;
	int x=0,ans=0;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+0,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]+d>=a[j])
			{
				ans++;
			}
			else break;
		}
	}
	printf("%d",ans);
	return 0;
}


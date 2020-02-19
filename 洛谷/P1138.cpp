#include<bits/stdc++.h>
using namespace std;
int a[30001];
int main()
{
	int n;
	int k;
	int tmp,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		a[tmp]++;
	}
	for(int i=0;i<30001;i++)
	{
		if(a[i]==0)continue;
		ans++;
		if(ans==k)
		{
			printf("%d",i);
			return 0;
		}
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001]; 
int main()
{
	int ans=-0x7fffffff;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=max(b[i-1]+a[i],a[i]);
		ans=max(ans,b[i]);
	}
	printf("%d\n",ans);
	return 0;
}



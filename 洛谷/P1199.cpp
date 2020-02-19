#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main()
{
	int n,ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
        for(int j=i+1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
		}
	}
	printf("1\n");
    for(int i=1;i<=n;i++)
	{
		sort(a[i]+1,a[i]+n+1);
		ans=max(ans,a[i][n-1]);
	}
	printf("%d",ans);
    return 0;
}

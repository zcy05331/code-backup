#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    sort(a,a+n);
    int ans=0,sum=0;
    for(int i=n-1;i>=0;i--)
	{
        sum+=a[i];
        ans++;
        if(sum>=m)
		{
            break;
		}
	}
	printf("%d",ans);
    return 0;
}

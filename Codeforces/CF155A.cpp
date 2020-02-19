#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
	}
    int ans=0;
    int maxx=a[0],minn=a[0];
    for(int i=1;i<n;i++)
	{
        if(a[i]>maxx)ans++,maxx=a[i];
        if(a[i]<minn)ans++,minn=a[i];
	}
    printf("%d",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long  a[100005]={};
int   main()
{
    a[0]=0;
    long long  n, m;
    scanf( "%lld%lld", &n, &m );
    for( int   i=1; i<=n; i++ )
        scanf( "%lld", &a[i] );
	long long  maxn=0;
    for(int i=0;i<=n;i++)
	{
        if(i%2==0)maxn-=a[i];
        else maxn+=a[i];
	}
    if(n%2==0)maxn+=m;
    int tmp;
    for(int i=0;i<n;i++)
	{
        if(a[i+1]-a[i]>1)
		{
            tmp=a[i+1]-1;
            break;
		}
	}
    a[++n]=tmp;
    sort(a,a+n+1);
    long long  maxn2=0;
    for(int  i=0;i<=n;i++)
	{
        if(i%2==0)maxn2-=a[i];
        else maxn2+=a[i];
	}
    if(n%2==0)maxn2+=m;
    printf("%lld %lld",maxn2,maxn);
    return 0;
}

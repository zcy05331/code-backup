#include<bits/stdc++.h>
using namespace std;
int a[101];
int g[20001];
int b[20001];
int main()
{
    int n, ans=0;
    scanf( "%d", &n );
    for( int i=1; i<=n; i++ )
    {
        scanf( "%d", &a[i] );
        b[a[i]]=1;
    }
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)g[a[i]+a[j]]=1;
		}
	}
	for(int i=3;i<=20000;i++)
	{
		if(g[i]==1&&b[i]==1)ans++;
	}
    printf( "%d", ans );
    return 0;
}

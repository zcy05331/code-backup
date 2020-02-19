#include<bits/stdc++.h>
using namespace std;
int a[100001];
int v[100001];
int main()
{
    int n, k, l, m;
    scanf( "%d%d%d", &n, &k, &l );
    m=n*k;
    for( int i=0; i<m; i++ )
    {
        scanf( "%d", &a[i] );
    }
    sort( a, a+m );
    long long ans=0;
    for( int i=0; i<n; i++ )
    {
        v[i]=a[i];
        ans+=v[i];
    }
    if( ( v[n-1]-v[0] )>l )
        printf( "0" );
    else
        printf( "%I64d", ans );
    return 0;
}

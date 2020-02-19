#include<bits/stdc++.h>
using namespace std;
long long f[50];
const  long long mod=2147483648;
long long a[10001], cnt;
int work( long long x )
{
    long long y=2;
    while( x>1 )
    {
        if( x%y==0 )
            x/=y, a[++cnt]=y;
        else
            y++;
    }
    for( int i=1; i<=cnt; i++ )
    {
        if( i!=cnt )
            printf( "%d*", a[i] );
        else
            printf( "%d", a[i] );
    }
    return 0;
}
int main()
{
    int n;
    f[0]=0;
    f[1]=1;
    scanf( "%d", &n );
    for( int i=2; i<=n; i++ )
    {
        f[i]=( f[i-1]+f[i-2] )%mod;
    }
    printf( "%lld=", f[n] );
    work( f[n] );
    return 0;
}

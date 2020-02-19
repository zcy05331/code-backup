#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
    int n;
    scanf ( "%d", &n );
    for ( int i = 0; i < n; i++ )
    {
        scanf ( "%d", &a[i] );
    }
    sort ( a, a + n );
    for ( int i = 1; i < n / 2; i++ )
    {
        if ( a[i] != a[i - 1] )
        {
            printf ( "NO" );
            return 0;
        }
    }
    for ( int i = n / 2 + 1; i < n; i++ )
    {
        if ( a[i] != a[i - 1] )
        {
            printf ( "NO" );
            return 0;
        }
    }
    int flag = 1;
    for ( int i = 1; i < n; i++ )
    {
        if ( a[i] != a[i - 1] )
            flag = 0;
    }
    if ( flag )
    {
        printf ( "NO" );
        return 0;
    }
    printf ( "YES\n%d %d", a[0], a[n - 1] );
    return 0;
}

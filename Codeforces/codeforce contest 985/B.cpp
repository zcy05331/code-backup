#include<bits/stdc++.h>
using namespace std;
char a[2001][2001];
int g[2001][2001];
int t[2001];
int main()
{
    int n, m;
    scanf( "%d%d", &n, &m );
    for( int i=0; i<n; i++ )
    {
        scanf( "%s", a[i] );
        for( int j=0; j<m; j++ )
        {
            g[i][j]=( a[i][j]-'0' );
        }

    }
    for( int i=0; i<m; i++ )
    {
        for( int j=0; j<n; j++ )
        {
            if( g[j][i] ==1 )
                t[i]++;
        }
    }
    for( int i=0; i<n; i++ )
    {
        int flag=1;
        for( int j=0; j<m; j++ )
        {
            if( g[i][j]==1 )
                t[j]--;
            if( t[j]<=0 )
            {
                flag=0;
            }
        }
        if( flag )
        {
            printf( "YES" );
            return 0;
        }
        else
        {
            for( int j=0; j<m; j++ )
            {
                if( g[i][j]==1 )
                    t[j]++;
            }
        }
    }
    printf( "NO" );
    return 0;
}

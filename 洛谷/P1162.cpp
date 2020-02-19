#include<bits/stdc++.h>
using namespace std;
int n;
int a[31][31];
int dfs ( int x, int y )
{
    if ( x < 1 || x > n || y < 1 || y > n || a[x][y] != 0 )
        return 0;
    else
    {
        a[x][y] = -1;
        dfs ( x + 1, y );
        dfs ( x - 1, y );
        dfs ( x, y - 1 );
        dfs ( x, y + 1 );
    }
}
int main()
{
    scanf ( "%d", &n );
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            scanf ( "%d", &a[i][j] );
        }
    }
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            if ( a[i][j] == 0 && ( i == 1 || j == 1 || i == n || j == n ) )
            {
                dfs ( i, j );
            }
        }

    }
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= n; j++ )
        {
            if ( a[i][j] == -1 )
                putchar ( '0' );
            else if ( a[i][j] == 1 )
                putchar ( '1' );
            else if ( a[i][j] == 0 )
                putchar ( '2' );
            putchar ( ' ' );
        }
        puts ( "" );
    }
    return 0;
}

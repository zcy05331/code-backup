#include<bits/stdc++.h>
using namespace std;
char a[501][501];
int main()
{
    int n, m;
    scanf ( "%d%d", &n, &m );
    for ( int i = 0; i < n; i++ )
    {
        scanf ( "%s", a[i] );
    }
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < m; j++ )
        {
            if ( a[i][j] == 'W' && ( a[i][j + 1] == 'S' || a[i][j - 1] == 'S' || a[i + 1][j] == 'S' || a[i - 1][j] == 'S' ) )
            {
                printf ( "No\n" );
                return 0;
            }

            if ( a[i][j + 1] == '.' )
                a[i][j + 1] = 'D';
            if ( a[i][j - 1] == '.' )
                a[i][j - 1] = 'D';
            if ( a[i + 1][j] == '.' )
                a[i + 1][j] = 'D';
            if ( a[i - 1][j] == '.' )
                a[i - 1][j] = 'D';

        }
    }
    printf ( "Yes\n" );
    for ( int i = 0; i < n; i++ )
    {
        for ( int j = 0; j < m; j++ )
        {

            printf ( "%c", a[i][j] );
        }
        puts ( "" );
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int a[201][201];
int f[201][201] = {};
int n, m;
int dfs ( int x, int y )
{
    if ( f[x][y] )
        return f[x][y];
    else
    {
        int t = 1;
        for ( int i = 0; i < 4; i++ )
        {
            int nx = x + dx[i], ny = y + dy[i];
            if ( nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[x][y] < a[nx][ny] )
            {
                t = max ( dfs ( nx, ny ) + 1, t );
            }
        }
        f[x][y] = t;
        return t;
    }
}
int main()
{

    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
        {
            scanf ( "%d", &a[i][j] );
        }
    }
    int ans = 0, tmp = 1;
    for ( int i = 1; i <= n; i++ )
    {
        for ( int j = 1; j <= m; j++ )
        {
            tmp = dfs ( i, j );
            f[i][j] = tmp;
            ans = max ( ans, f[i][j] );
        }
    }
    printf ( "%d\n", ans );
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int dx[]= {0, 1, 0, -1}, dy[]= {1, 0, -1, 0};
int n, m, k;
char s[1001][1001];
int a[1001][1001];
int f[1001*1001];
int vis[1001][1001];
int check(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m;
}
int dfs ( int x, int y, int c )
{

    vis[x][y]=c;
    int ans=0;
    for ( int i=0; i<=3; i++ )
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(check(nx,ny)&&!vis[nx][ny])
        {
            if(a[nx][ny]==1)ans++;
            else ans+=dfs(nx,ny,c);
        }

    }

    return ans;
}
int main()
{

    scanf ( "%d%d%d", &n, &m, &k );
    for ( register  int i=0; i<n; ++i )
    {
        scanf ( "%s", s[i] );
        for ( register  int j = 0 ; j < m ; ++j )
        {
            if ( s[i][j]=='*' )
                a[i][j]=1;
        }
    }
    int num=0;
    int x, y;
    for ( int i=1; i<=k; i++ )
    {
        scanf ( "%d%d", &x, &y );
        if ( f[vis[x-1][y-1]]!=0 )
        {
            printf ( "%d\n", f[vis[x-1][y-1]] );
        }
        else
        {
            num++;
            f[num]=dfs ( x-1, y-1, num );
            printf ( "%d\n", f[num] );
        }
    }
    return 0;
}

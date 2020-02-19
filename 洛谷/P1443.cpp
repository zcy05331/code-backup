#include<bits/stdc++.h>
using namespace std;
const int dx[8]={2,-2,2,-2,-1,1,-1,1},dy[8]={1,1,-1,-1,2,2,-2,-2};
int n, m;
int stx, sty;
int vis[401][401];
struct node
{
    int x;
    int y;
    int cost;
    node(){}
    node(int x,int y,int cost):x(x),y(y),cost(cost){}
};
queue<node>q;
int bfs()
{
    q.push(node(stx,sty,0));
    vis[stx][sty]=0;
    while( !q.empty() )
    {
    	node tmp;
        tmp=q.front();
        q.pop();
        int px=tmp.x, py=tmp.y,c=tmp.cost;
        for( int i=0; i<=7; i++ )
        {
            int nx=px+dx[i],ny=py+dy[i];
            if(nx<=0||nx>n||ny<=0||ny>m)continue;
            if(vis[nx][ny]==-1)
			{
                vis[nx][ny]=c+1;
                q.push(node(nx,ny,c+1));
			}

        }
    }

}
int main()
{
    memset( vis, -1, sizeof( vis ) );
    scanf( "%d%d%d%d", &n, &m, &stx, &sty );
    bfs();
    for( int i=1; i<=n; i++ )
    {
        for( int j=1; j<=m; j++ )
        {
            printf( "%-5d", vis[i][j] );
        }
        puts( "" );
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int s[5000];
char c[5000];
char t[5000];
int dfs( int id, int l, int r )
{
    int sum=s[r]-s[l-1];
    int mid=( l+r )>>1;
    if( sum==( r-l+1 ) )
        t[id]='I';
    else if( sum==0 )
        t[id]='B';
    else
        t[id]='F';
    if( l!=r )
    {
        dfs( 2*id, l, mid );
        dfs( 2*id+1, mid+1, r );
    }

    printf( "%c", t[id] );
}
int main()
{
    int n;
    scanf( "%d", &n );
    scanf( "%s", c+1 );
    int len=1<<n;
    for( int i=1; i<=len; i++ )
    {
        s[i]=s[i-1]+( c[i]-'0' );
    }
    dfs( 1, 1, len );
    return 0;
}

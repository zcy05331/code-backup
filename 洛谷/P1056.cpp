#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int b[1001], c[1001];
int main()
{
    int m, n, k, l, d;
    int x, y, p, q;
    scanf( "%d%d%d%d%d", &m, &n, &k, &l, &d );
    for( int i=1; i<=d; i++ )
    {
        scanf( "%d%d%d%d", &x, &y, &p, &q );
        if( x==p )
            b[min( y, q )]++;
        else
            c[min( x, p )]++;
    }

    return 0;
}

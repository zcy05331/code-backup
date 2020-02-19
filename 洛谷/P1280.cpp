#include<bits/stdc++.h>
using namespace std;
struct node
{
    int b, t;
} a[10001];
int f[10001];
int cmp( const node &a, const node &b )
{
    return a.b>b.b;
}
int sum[10001];
int main()
{
    int n,k;
    scanf( "%d%d", &n, &k );
    for( int i=1; i<=k; i++ )
    {
        scanf( "%d%d", &a[i].b, &a[i].t );
        sum[a[i].b]++;
    }
    sort( a+1, a+k+1, cmp );
    int num=1;
    for( int i=n; i>=1; i-- )
    {
        if( sum[i]==0 )
            f[i]=f[i+1]+1;
        else
        {
            for( int j = 1 ; j <= sum[i]; j++ )
            {
				if(f[i]<f[i+a[num].t])
                    f[i]=f[i+a[num].t];
                num++;
            }
        }

    }
    printf( "%d", f[1] );
    return 0;
}

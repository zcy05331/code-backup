#include<bits/stdc++.h>
using namespace std;
int n, a[101];
int main()
{
    int sum=0;
    scanf( "%d", &n );
    for( int i=0; i<n; i++ )
    {
        scanf( "%d", &a[i] );
        sum+=a[i];
    }
    if( n==1 )
    {
        puts( "-1" );
        return 0;
    }
    int maxn=1<<n-1;
    for( int i=1; i<=maxn; i++ )
    {
        int x=0, k=0;
        for( int j=0; j<n; j++ )
        {
            if( i&( 1<<j ) )
                x+=a[j], k++;
        }
        //printf("%d %d %d\n",i,x,k);
        if( x!=sum-x&&k!=0&&k!=n )
        {
            printf( "%d\n", k );
            for( int j=0; j<n; j++ )
            {
                if( i&( 1<<j ) )
                    printf("%d ",j+1);
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}

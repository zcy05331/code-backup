#include<bits/stdc++.h>
using namespace std;
const long long mod=100000000;
struct matrix
{
    int row, col;
    long long mat[101][101];
    matrix( int n, int m ):row( n ), col( m )
    {
        memset( mat, 0, sizeof( mat ) );
    }
    matrix operator *( matrix m )
    {
        if( col!=m.row )
            return matrix( 1, 1 );
        int lenr=row, lenc=m.col, l=col;
        matrix ans( lenr, lenc );
        for( int i=0; i<lenr; i++ )
        {
            for( int j=0; j<l; j++ )
            {
                for( int k=0; k<lenc; k++ )
                {
                    ans.mat[i][j]+=( mat[i][k]*m.mat[k][j] )%mod;
                    ans.mat[i][j]%=mod;
                }
            }
        }
        return ans;
    }
    matrix operator = ( matrix m )
    {
        row=m.row;
        col=m.col;
        for( int i=0; i<row; i++ )
        {
            for( int j=0; j<col; j++ )
            {
                mat[i][j]=m.mat[i][j];
            }
        }
    }
};
matrix pow( matrix a, int k )
{
    matrix res=a;
    for( ; k; k/=2, a=a*a )
    {
        if( k&1 )
            res=res*a;
    }
    return res;
}
int main()
{
    int n, m;
    scanf( "%d%d", &n, &m );
    long long k=__gcd( n, m );
    if( k<=2 )
    {
        printf( "1" );
        return 0;
    }
    matrix x( 2, 2 );
    x.mat[0][0]=x.mat[0][1]=x.mat[1][0]=1;
    matrix ans( 2, 2 );
    ans=pow( x, k-2 );
    printf( "%d\n", ans.mat[0][0] );
    return 0;
}

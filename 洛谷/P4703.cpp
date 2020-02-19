#include<bits/stdc++.h>
using namespace std;
double x[101], y[101];
double l, n;
int main()
{
    srand( 19260817 );

    scanf( "%lf%lf", &n, &l );
    for( int i=0; i<n; i++ )
    {
        scanf( "%lf%lf", &x[i], &y[i] );
    }

    for( int i=0; i<2000000; ++i )
    {
        double nx=rand(), ny=rand();
        while( nx>l )
            nx/=10;
        while( ny>l )
            ny/=10;
        bool flag=true;
        for( int j=0; j<n; j++ )
        {

            if( pow( nx - x[j], 2 ) + pow( ny - y[j], 2 ) < pow( l / n, 2 ) )
            {
                flag=false;
                break;
            }

        }
        if( flag )
        {
            printf( "%.3f %.3f\n", nx, ny );
            return 0;
        }
    }
    puts( "GG" );
    return 0;
}

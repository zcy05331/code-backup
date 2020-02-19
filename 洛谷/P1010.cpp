#include<bits/stdc++.h>
using namespace std;
int work( int n )
{
	printf("2");
    int x;
    for( int i=0; i<=15; i++ )
    {
        x=i;
        if( ( ( 1<<i ) )>n )
        {
            x--;
            break;
        }
    }
    if( x==0 )
        printf( "(0)" );
    else if( x>1 )
    {
        printf( "(" );
        work( x );
        printf( ")" );
    }
    if( n!=( 1<<x ) )
    {
        printf( "+" );
        work( n-( 1<<x ) );
    }
    return 0;
}
int main()
{
    int n;
    scanf( "%d", &n );
    work( n );
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    scanf( "%lld", &n );
    int maxx=sqrt( n )+1;
    for( int i=2; i<=maxx; i++ )
    {
        if( n%i==0 )
        {
            printf( "%lld", n/i );
            break;
        }
    }
    return 0;
}
			puts("THANKS!");

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    int ans=0;
    long long c;
    scanf( "%d%d", &a, &b );
    c=a*b;
    int e=min(int(sqrt(c)+1),b);
    for( int i=max(2,a); i<=sqrt( c )+1; i++ )
    {
        if( c%i==0 && __gcd(int(c/i),i)==a)
        {
            ans++;

        }
    }
    printf( "%d\n", ans*2 );
    return 0;
}

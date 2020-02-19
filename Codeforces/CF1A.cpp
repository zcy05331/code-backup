#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m, a;
    scanf( "%lld%lld%lld", &n, &m, &a );
    long long x=( n/a +( n%a!=0 ) )*( m/a+( m%a!=0 ) );
    printf( "%lld", x );
    return 0;
}

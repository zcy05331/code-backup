#include<bits/stdc++.h>
using namespace std;
int a, b;
int ok[10000];
int cnt=0;
int pow10( int s )
{
    int xs=1;
    for( int i=1; i<=s; i++ )
        xs*=10;
    return xs;

}
int ith( int x, int num )
{
    int s=pow10( num );
    int sx=s/10;
    return ( x%s )/sx;
}
int pd1( int x )
{
    int up, down;
    for( int i=1; i<=4; i++ )
    {
        up=ith( x, 9-i );
        down=ith( x, i );
        if( up!=down )
            return 0;
    }
    return 1;
}
int pd2( int x )
{
    int y=x/10000;
    int m=x%10000/100;
    int d=x%100;
    // printf("%lld",x);
    if( m>=13||m==0 )
        return 0;
    if( d>31||d==0 )
        return 0;
    if( ( m==4||m==6||m==9||m==11 )&&d>=31 )
        return 0;
    if( ( ( y%4==0 && y%100!=0 )|| y%400==0 )&&d>=30&&m==2 )
        return 0;
    if( ( y%4!=0||y%100==0 ) &&d>=29 &&m==2 )
        return 0;
    return 1;
}
int main()
{
    int ans=0;
    scanf( "%lld%lld", &a, &b );
    int ay=a/10000;
    int by=b/10000;
    for( int i=ay; i<=by; i++ )
    {
        int x=i;
        x=x*10+x%10;
        x=x*10+x%1000/100;
        x=x*10+x%100000/10000;
        x=x*10+x%10000000/1000000;
        if( a<=x&&b>=x )
            ok[++cnt]=x;
    }
    for( int i=1; i<=cnt; i++ )
    {
        if( pd2( ok[i] ) )
            ans++;
    }
    printf( "%d", ans );
    return 0;
}

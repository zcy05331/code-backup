#include<bits/stdc++.h>
#include<string>
using namespace std;
string a[10001];
int check( string a, string b )
{
    int lena=a.length(), lenb=b.length();
    for( int i=0; i<=lenb-lena; i++ )
    {
        int flag=1;
        for( int j=i; j<i+lena; j++ )
        {
            if( a[j-i]!=b[j] )
                flag=0;
        }
        if( flag )
            return 1;
    }
    return 0;
}
int cmp( string a, string b )
{
    if( a.length()!=b.length() )
        return a.length()<b.length();
    else
    {
        int len=b.length();
        for( int i=0; i<len; i++ )
        {
                return a[i]<b[i];
        }
    }

}//233
int main()
{
    int n;
    scanf( "%d", &n );
    for( int i=0; i<n; i++ )
    {
        cin>>a[i];
    }
    sort( a, a+n, cmp );
    for( int i=0; i<n; i++ )
    {
        for( int j=i+1; j<n; j++ )
        {

            if( !check( a[i], a[j] ) )
            {
                printf( "NO" );
                return 0;
            }
        }
    }
    puts( "YES" );
    for( int i=0; i<n; i++ )
        puts( a[i].c_str() );
    return 0;
}

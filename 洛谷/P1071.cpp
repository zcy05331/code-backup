#include<bits/stdc++.h>
using namespace std;
map<char, char>to;
char a[1001],b[1001],c[1001];
int main()
{
    for( char i='A'; i<='Z'; i++ )
        to[i]='\n';
    scanf( "%s", a );
    scanf( "%s", b );
    scanf( "%s", c );
    int n=strlen( a ), m=strlen( c );
    for( int i=0; i<n; i++ )
    {
        if( to[a[i]]=='\n' )
            to[a[i]]=b[i];
        else if( to[a[i]]!=b[i] )
        {
            //printf("%c %c %c ",a[i],b[i],to[a[i]]);
            puts( "Failed" );
            return 0;
        }
    }
    for( char i='A'; i<='Z'; i++ )
        if( to[i]=='\n' )
        {
            puts( "Failed" );
            return 0;
        }
    for( char i='A'; i<='Z'; i++ )
        for( char j='A'; j<='Z'; j++ )
            if( i!=j&&to[i]==to[j] )
            {
                puts( "Failed" );
                return 0;
            }
    for(int i=0;i<m;i++)
    {
        c[i]=to[c[i]];
        putchar(c[i]);
    }
    return 0;
}

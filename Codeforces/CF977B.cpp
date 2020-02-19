#include<bits/stdc++.h>
#include<map>//233
using namespace std;
map<string, int>s;
string a;
int main()
{
    int n;
    scanf( "%d", &n );
    cin>>a;
    string x;
    for( int i=0; i<n-1; i++ )
    {

        x=a.substr(i,2);
        s[x]++;
    }
    int max=-1;
    for( map<string, int>::iterator i=s.begin(); i!=s.end(); i++ )
    {
        if(i->second>max)
		{
            max=i->second;
            x=i->first;
		}
    }
    printf("%s",x.c_str());
    return 0;
}

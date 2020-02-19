#include<bits/stdc++.h>
using namespace std;
struct mem
{
    int  x;
    string s;
}a[100001];
int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].x);
		cin>>a[i].s;
	}
    int pos=0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==a[pos].x)
		{
            pos=(pos-y)%n;
            if(pos<0)pos+=n;
		}
		else
		{
            pos=(pos+y)%n;
		}
    }
    printf("%s",a[pos].s.c_str());
    return 0;
}

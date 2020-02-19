#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a=0,b=0;
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d",&x,&y);
        if(x>y)a++;
        else if(x<y)b++;
	}
    if(a==b)puts("Friendship is magic!^^");
    else if(a<b)puts("Chris");
    else puts("Mishka");
    return 0;
}

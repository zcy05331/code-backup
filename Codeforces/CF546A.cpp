#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    int n,w;
    scanf("%d%d%d",&k,&n,&w);
    for(int i=1;i<=w;i++)
	{
        n-=k*i;
	}
    n=min(n,0);
    printf("%d",-n);
    return 0;
}

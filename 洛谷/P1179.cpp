#include<bits/stdc++.h>
using namespace std;
int main()
{
	int l,r;
	long long ans=0;
    scanf("%d%d",&l,&r);
    for(int i=l;i<=r;i++)
	{
        int x=i;
        while(x)
		{
			if(x%10==2)ans++;
			x/=10;
		}
	}
    printf("%lld",ans);
    return 0;
}

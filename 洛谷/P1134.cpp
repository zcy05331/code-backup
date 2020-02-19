#include<bits/stdc++.h>
using namespace std; 
int main()
{
    int n,x=0;
	long long ans=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		//x=i%10;
		ans*=i;
		while(ans%10==0)ans/=10;
		ans%=10000000;
	//	printf("%d\n",ans);
	} 
	printf("%lld",ans%10);
	return 0;
}


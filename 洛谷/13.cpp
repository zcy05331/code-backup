#include<bits/stdc++.h>
using namespace std;
int ans=1;
void work(int n)
{
	if(n<=1)return;
	ans+=n/2;
	for(int i=1;i<=n/2;i++)
	{
		work(i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	work(n);
	printf("%d",ans);
	return 0;
}


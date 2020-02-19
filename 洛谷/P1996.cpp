#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int left=n,tmp=1,now=1;
	while(left>0)
	{
		now++;
		if(now>n)now=1; 
		if(a[now]==0)
		{
			tmp++;
		}
		if(tmp==m)
		{
			left--;
			a[now]=1;
			printf("%d ",now);
			tmp=0;
		}
	}
	return 0;
}


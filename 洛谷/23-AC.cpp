#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
int a[30001]={};
int main()
{
	register int w,n;
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a+0,a+n);
	int tail=0,head=n-1,ans=0;
	while(head>tail)
	{
		++ans;
		if(a[head]+a[tail]>w)
		{
			--head;
		}
		else
		{
			--head;
			++tail;
		}
	}
	if(head==tail)++ans;
	printf("%d",ans);
	return 0;
}


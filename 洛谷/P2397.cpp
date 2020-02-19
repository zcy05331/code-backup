#include<bits/stdc++.h>
#include<stack>
using namespace std;
int h,cnt;
int main()
{
	int n,tmp=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		if(h==tmp)cnt++;
		if(cnt==0)
		{
			cnt++;
			h=tmp;
		}
		if(h!=tmp)
		{
			cnt--;
		}
	} 
	printf("%d",h);
	return 0;
}


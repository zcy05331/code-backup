#include<bits/stdc++.h>
using namespace std;
stack<int>x;
int a[10000001];
int main()
{
	int n,tmp,ans;
	scanf("%d",&n);
	scanf("%d",&ans);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&tmp);
		ans^=tmp;
	}
	printf("%d",ans);
	return 0;
}


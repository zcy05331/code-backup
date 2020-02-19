#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	int num=1;
    int cnt=0;
    int ans=0;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
	{
		cnt++;
		ans+=num;
		if(num==cnt)
		{
			num++;
			cnt=0;
		}
	}
	printf("%d",ans);
    return 0;
}

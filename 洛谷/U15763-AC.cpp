#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
pair <int,int>a[1001]={};
int time[10001]={};
int main()
{
	int t,ans=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&a[i].first,&a[i].second);
		for(int j=a[i].first;j<a[i].second;j++)
		{
			time[j]++;
		}
	}
	for(int i=0;i<10001;i++)
	{
		if(time[i]>ans)ans=time[i];
	}
	printf("%d",ans);
	return 0;
}


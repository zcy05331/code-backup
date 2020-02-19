#include<bits/stdc++.h>
using namespace std;
int a[1001];
int b[6]={1,2,3,5,10,20};
int f[1001];
int main()
{
	int tmp,num=0,ans=0;
	for(int i=0;i<6;i++)
	{
		scanf("%d",&tmp);
		for(int j=0;j<tmp;j++)
		{
			a[num++]=b[i];
			//f[b[i]]=1;
		}
	}
	f[0]=1;
	for(int i=0;i<num;i++)
	{
		for(int j=999;j>=0;j--)
		{
			if(f[j])f[j+a[i]]=1;
		}
	}
	for(int i=1;i<1000;i++)
	{
		if(f[i])ans++;
	}
	printf("Total=%d\n",ans);
	return 0;
}



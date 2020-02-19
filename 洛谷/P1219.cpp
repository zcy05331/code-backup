#include<bits/stdc++.h>
using namespace std;
int n,ans,sum=0;
int a[14];
int tmp[14]= {},b[14],c[28],d[28];
void print()
{
	if(sum<3)
	{
		for(int i=0; i<n; i++)
		{
			printf("%d ",a[i]+1);
		}
		puts("");

	}
	sum++;
}
void tryy(int x)
{

	for(int i=0; i<n; i++)
	{
		if(!b[i]&&!c[x+i]&&!d[x-i+n-1])
		{
			a[x]=i;
			b[i]=1 ;
			c[x+i]=1 ;
			d[x-i+n-1]=1;
			tryy(x+1);
			if(x==n-1)//回朔的输出还是放这里比较好 
			{
				print();
			}
			b[i]=0;
			c[x+i]=0;
			d[x-i+n-1]=0;

		}
	}
}
int main()
{
	scanf("%d",&n);
	tryy(0);
	printf("%d",sum);
	return 0;
}

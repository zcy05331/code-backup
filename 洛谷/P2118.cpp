#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,l,c,d;
	long double ans=100;
	scanf("%d%d%d",&a,&b,&l);
    for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=l;j++)
		{
            if((long double)(i*1.0/j)-(long double)(a*1.0/b)>=0&&(long double)(i*1.0/j)-(long double)(a*1.0/b)<ans)
			{
				ans=((long double)(i*1.0/j)-(long double)(a*1.0/b));
				c=i;
				d=j;
			}
		}
	}
	printf("%d %d",c,d);
    return 0;
}

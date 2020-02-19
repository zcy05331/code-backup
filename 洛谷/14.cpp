#include<bits/stdc++.h>
using namespace std;
int a[1000]= {};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n; i>=0; i--)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n; i>=0; i--)
	{
		if(a[i]!=0)
		{
			if(i==n)
			{
				if(abs(a[i])==1)
				{
					if(a[i]==1)
					{
						printf("x^%d",i);
					}
					else
					{
						printf("-x^%d",i);
					}
				}
				else
				{
					printf("%dx^%d",a[i],i);
				}

			}
			else if(i==0)
			{
				if(a[i]>0)
				{
					printf("+%d",a[i]);
				}
				else
				{
					printf("%d",a[i]);
				}
			}
			else if(i==1)
			{
				if(a[i]>0)
				{
					if(a[i]==1)
					{
						printf("+x");
					}
					else
					{

						printf("+%dx",a[i]);
					}
				}
				else
				{
					if(a[i]==-1)
					{
						printf("-x");
					}
					else
					{
						printf("%dx",a[i]);
					}

				}
			}
			else
			{
				if(a[i]>0)
				{
					if(a[i]==1)
					{
						printf("+x^%d",i);
					}
					else
					{

						printf("+%dx^%d",a[i],i);
					}
				}
				else
				{
					if(a[i]==-1)
					{
						printf("-x^%d",i);
					}
					else
					{
						printf("%dx^%d",a[i],i);
					}

				}
			}
		}
	}
	return 0;
}


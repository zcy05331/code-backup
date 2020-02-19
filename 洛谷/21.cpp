#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cctype>
#include<string>
using namespace std;
char a[1000]= {};
int main()
{
	register int p1,p2,p3;
	scanf("%d%d%d",&p1,&p2,&p3);
	scanf("%s",a);
	register int len=strlen(a);
	for(int i=0; i<len; i++)
	{
		if(a[i]!='-')printf("%c",a[i]);
		else if(a[i-1]>=a[i+1])printf("%c",a[i]);
		else if((isdigit(a[i-1])&&isalpha(a[i+1]))||(isdigit(a[i+1])&&isalpha(a[i-1]))||!(isalnum(a[i-1])))printf("%c",a[i]);
		else if(p1==3)
		{
			for(int j=0; j<p2*(-a[i-1]+a[i+1]-1); j++)
			{
				printf("*");
			}
		}
		else if(p1==1)
		{
			if(p3==1)
			{
				for(int j=0; j<(+a[i+1]-a[i-1]-1); j++)
				{
					for(int k=1; k<=p2; k++)
					{
						printf("%c",tolower(a[i-1]+j+1));
					}

				}
			}
			else if(p3==2)
			{
				for(int j=(+a[i+1]-a[i-1]-2); j>=1; j--)
				{
					for(int k=1; k<=p2; k++)
					{
						printf("%c",tolower(a[i-1]+j+1));
					}

				}
			}
		}
		else if(p1==2)
		{
			if(p3==1)
			{
				for(int j=0; j<(+a[i+1]-a[i-1]-1); j++)
				{
					for(int k=1; k<=p2; k++)
					{
						printf("%c",toupper(a[i-1]+j+1));
					}

				}
			}
			else if(p3==2)
			{
				for(int j=(+a[i+1]-a[i-1]-2); j>=0; j--)
				{
					for(int k=1; k<=p2; k++)
					{
						printf("%c",toupper(a[i-1]+j+1));
					}

				}
			}
		}
	}
	return 0;
}


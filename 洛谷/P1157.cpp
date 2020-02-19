#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
int a[21]= {},b[21]= {},r,n;
int print()
{
	for(int i=0; i<r; i++)
	{
		cout<<setw(3)<<a[i]+1;
	}
	printf("\n");
}
int tryy(int x)
{
	for(int i=0; i<n; i++)
	{
		if(!b[i]&&i+1>a[x-1])
		{
			b[i]=1;
			a[x]=i;
			if(x==r-1)
			{
				print();
			}
			else
			{
				tryy(x+1);
			}
			b[i]=0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	tryy(0);
	return 0;
}

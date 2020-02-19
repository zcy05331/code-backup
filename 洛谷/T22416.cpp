#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001];
int s1[100001],s2[100001];
int main()
{
	int  T,n;
	scanf("%d",&T);
as:
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			s1[i]=s1[i-1]+a[i];
		}
		for(int i=0; i<n; i++)
		{
			scanf("%d",&b[i]);
			s2[i]=s2[i-1]+b[i];
		}
		sort(s1,s1+n);
		sort(s2,s2+n);
		for(int i=0; i<n; i++)
		{
			if(s1[i]!=s2[i])
			{
				puts("Rua");
				goto as;
			}
		}
		puts("EL PSY CONGROO");
	}
	return 0;
}


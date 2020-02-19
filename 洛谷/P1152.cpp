#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001];
int main()
{
    int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<n;i++)
	{
		tmp=abs(a[i]-a[i-1]);
		if(b[tmp]!=0)
		{
			printf("Not jolly");
			return 0;
		}  
		b[tmp]++;
	} 
	printf("Jolly");
	return 0;
}


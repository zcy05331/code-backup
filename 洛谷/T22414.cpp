#include<bits/stdc++.h>
using namespace std;
int a[10001]  ;
int main()
{
    int n,ans=0,max=0;
	scanf("%d",&n);  
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
		{
			ans++;
			max=a[i];
		}
	} 
	printf("%d",ans);
	return 0;
}


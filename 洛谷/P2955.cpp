#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	char a[61];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		int l=strlen(a);
		if((a[l-1]-'0')%2==0)puts("even");
		else puts("odd");
	}
	
	return 0;
}


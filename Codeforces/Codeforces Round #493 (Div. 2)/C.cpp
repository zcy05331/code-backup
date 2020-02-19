#include<bits/stdc++.h>
using namespace std;
char a[3000001];
int main()
{
    long long n,x,y;
    scanf("%I64d%I64d%I64d",&n,&x,&y);
    scanf("%s",a);
    long long ans;
	long long  p=0;
    for(int i=0;i<n;i++)
	{
        if(a[i]!=a[i-1]&&a[i]=='0')p++;
	}
	if(p==0)
	{
		printf("0");
		return 0;
	}
    printf("%I64d",(p-1)*min(x,y)+y);
    return 0;
}

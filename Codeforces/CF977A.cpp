#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a;
    int n;
    scanf("%lld%d",&a,&n);
    while(a>0&&n)
	{
        n--;
        if(a%10)a--;
        else a/=10;
	}
	printf("%d",a);
    return 0;
}
 

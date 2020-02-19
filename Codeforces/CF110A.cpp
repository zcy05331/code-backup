#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int ans=0;
    scanf("%lld",&n);
    while(n)
	{
        if(n%10==4||n%10==7)ans++;
        n/=10;
	}
	if(ans==4||ans==7)puts("YES");
	else puts("NO");
    return 0;
}

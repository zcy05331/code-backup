#include<bits/stdc++.h>
using namespace std;
int a[101];
int odd[101],even[101];
int main()
{
	int n;
	scanf("%d",&n);
	int ans1=0,ans2=0;
    for(int i=1;i<=n/2;i++)
	{
        scanf("%d",&a[i]);
	}
	sort(a+1,a+n/2+1);
	for(int i=1;i<=n/2;i++)
	{
        odd[i]=i*2-1;
        even[i]=i*2;
        ans1+=abs(odd[i]-a[i]);
        ans2+=abs(even[i]-a[i]);
	}
    printf("%d",min(ans1,ans2));
    return 0;
}

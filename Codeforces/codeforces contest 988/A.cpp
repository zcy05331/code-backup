#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],c[1001];
int main()
{
    int n,k;
    int cnt=0;
    int cnt2=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a[i]);
        b[a[i]]++;
        if(b[a[i]]==1)cnt++;
	}
    if(cnt<k)
	{
        printf("NO");
        return 0;
	}
    puts("YES");
    for(int i=1;i<=n;i++)
	{
        if(!c[a[i]])
		{
            printf("%d ",i);
            c[a[i]]=1;
            cnt2++;
            if(cnt2==k)break;
		}
	}
    return 0;
}

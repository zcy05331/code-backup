#include<bits/stdc++.h>
using namespace std;
int a[10001];
int q[100001],head,tail=1;
int used[10001];
int main()
{
	int m,n,ans=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
        if(used[a[i]])continue;
        else
		{
			ans++;
            head++;
            q[head]=a[i];
            used[a[i]]=1;
            if(head-tail>=m)
			{
				used[q[tail]]=0;
                tail++;
			}
		}
	}
	printf("%d",ans);
    return 0;
}

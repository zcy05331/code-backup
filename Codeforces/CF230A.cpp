#include<bits/stdc++.h>
using namespace std;
struct dragon
{
    int hp,get;
}a[1001];
int cmp(const dragon &a,const dragon &b)
{
    if(a.hp!=b.hp)return a.hp<b.hp;
    return a.get>b.get;
}
int main()
{
    int s,n;
    int ans=0;
    scanf("%d%d",&s,&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d",&a[i].hp,&a[i].get);
	}
	sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
	{
        if(a[i].hp<s)
		{
			ans++;
            s+=a[i].get;
		}
		else break;
	}
	if(ans==n)printf("YES");
	else printf("NO");
    return 0;
}

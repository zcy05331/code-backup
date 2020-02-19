#include<bits/stdc++.h>
using namespace std;
struct ap
{
	int x,y;
}apple[5001];
int cmp(const ap &a,const ap &b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	int n,s,a,b,ans=0;
	scanf("%d%d%d%d",&n,&s,&a,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&apple[i].x,&apple[i].y);
	}
	sort(apple+0,apple+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(s<=0)break;
		if(a+b>=apple[i].x&&s>=apple[i].y)
		{
			s-=apple[i].y;
			ans++;
		}
	} 
	printf("%d",ans);
	return 0;
}


#include<cstdio>
using namespace std;
int n,m,k,x,use,a[1000001];
int f(int p)
{
	if(p==0) return 1;
	int tmp=f(p/2)%use;
	tmp=(tmp*tmp)%use;
	if(p%2==1) tmp=(tmp*10)%use;
	return tmp;
}
int find(int n,int m)
{
	int ans;
	for(int i=1; i<=m; i++)
	{
		if(m%i==0&&n%i==0)
		{
			ans=i;
		}
	}
	return n/ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&x);
	int temp=0,chan=x;
	use=find(n,m);
	a[temp]=x;
	while(temp<=use-1)
	{
		chan=(chan+m)%n;
		temp++;
		a[temp]=chan;
	}
	int l=f(k);
	printf("%d",a[l]);
	return 0;
}

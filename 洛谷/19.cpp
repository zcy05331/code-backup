#include<bits/stdc++.h>
using namespace std;
struct student
{
	int num;
	char name[1000];
	int final=0;
	int incla=0;
	char gb;
	char west;
	int lw;
	int prize;
} a[101];
int cmp(const student &a,const student &b)
{
	if(a.prize!=b.prize)
	{
		return a.prize>b.prize;
	}
	return a.num<b.num;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		a[i].num=i;
		scanf("%s %d %d %c %c %d",a[i].name,&a[i].final,&a[i].incla,&a[i].gb,&a[i].west,&a[i].lw);
		if(a[i].final>80&&a[i].lw>0)a[i].prize+=8000;
		if(a[i].final>85&&a[i].incla>80)a[i].prize+=4000;
		if(a[i].final>90)a[i].prize+=2000;
		if(a[i].final>85&&a[i].west=='Y')a[i].prize+=1000;
		if(a[i].incla>80&&a[i].gb=='Y')a[i].prize+=850;
	}
	sort(a+0,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		ans+=a[i].prize;
		//printf("%s %d\n",a[i].name,a[i].prize);
	}
	printf("%s\n%d\n%d",a[0].name,a[0].prize,ans);
	return 0;
}


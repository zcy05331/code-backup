#include<bits/stdc++.h>
using namespace std;
int a[1000]={},b[1000]={}; 
int rule[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0} };
int main()
{
	int n,na,nb,s1=0,s2=0,tmp1=0,tmp2=0;
	scanf("%d%d%d",&n,&na,&nb);
	for(int i=0;i<na;i++) scanf("%d",&a[i]);
	for(int i=0;i<nb;i++)scanf("%d",&b[i]);
	for(int i=0;i<n;i++) 
	{
		tmp1=i%na;
		tmp2=i%nb;
		s1+=rule[a[tmp1]][b[tmp2]];
		s2+=rule[b[tmp2]][a[tmp1]];
	}
	printf("%d %d",s1,s2); 
	return 0;
}


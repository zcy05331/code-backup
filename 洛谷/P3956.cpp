#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
#define R register
#define inf 0x7f
using namespace std;
int a[101][101]= {},b[101][101]= {};
int m,n,x,y,c;
void slove(int i,int j,int f,int cost,int color)
{
	if(i<0||j<0||i>=m||j>=m)
	{
		return;
	}
	b[i][j]=cost;
	if(a[i-1][j]&&cost+abs(color-a[i-1][j])<b[i-1][j])slove(i-1,j,1,cost+abs(color-a[i-1][j]),a[i-1][j]);
	if(a[i][j-1]&&cost+abs(color-a[i][j-1])<b[i][j-1])slove(i,j-1,1,cost+abs(color-a[i][j-1]),a[i][j-1]);
	if(a[i+1][j]&&cost+abs(color-a[i+1][j])<b[i+1][j])slove(i+1,j,1,cost+abs(color-a[i+1][j]),a[i+1][j]);
	if(a[i][j+1]&&cost+abs(color-a[i][j+1])<b[i][j+1])slove(i,j+1,1,cost+abs(color-a[i][j+1]),a[i][j+1]);
	if(f==1)
	{
		if(cost+2<b[i-1][j]&&!a[i-1][j])slove(i-1,j,0,cost+2,color);
		if(cost+2<b[i][j-1]&&!a[i][j-1])slove(i,j-1,0,cost+2,color);
		if(cost+2<b[i+1][j]&&!a[i+1][j])slove(i+1,j,0,cost+2,color);
		if(cost+2<b[i][j+1]&&!a[i][j+1])slove(i,j+1,0,cost+2,color);
	}
}
int main()
{
	memset(b,127,sizeof(b));
	scanf("%d%d",&m,&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x-1][y-1]=c+1;
	}
	int s=b[m-1][m-1];
	slove(0,0,1,0,a[0][0]);
	if(b[m-1][m-1]==s)
	{
		printf("-1");
		return 0;
	}
	else
	{
		printf("%d",b[m-1][m-1]);
	}
	return 0;
}


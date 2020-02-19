#include<bits/stdc++.h>
using namespace std;
int a[200][200]={};
int main()
{
    int n,d;
    int x,y,k;
	scanf("%d%d",&d,&n);
    int maxn=-1,cot=0;
    for(int i=0;i<n;i++)
	{
        scanf("%d%d%d",&x,&y,&k);
        a[x][y]=k;
	}
	int tmp;
    for(int i=0;i<=128;i++)
	{
        for(int j=0;j<=128;j++)
		{
			tmp=0;
            int fx,tx,fy,ty;
            fx=max(0,i-d);
            fy=max(0,j-d);
            tx=min(128,i+d);
            ty=min(128,j+d);
            for(int k=fx;k<=tx;k++)
			{
                for(int l=fy;l<=ty;l++)
                {
                    tmp+=a[k][l];
                }
			}
            if(tmp>maxn)
			{
                maxn=tmp;
                cot=1;
			}
			else if(tmp==maxn)
			{
                cot++;
			}
		}
	}
	printf("%d %d",cot,maxn);
    return 0;
}

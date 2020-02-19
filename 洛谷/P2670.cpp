#include<bits/stdc++.h>
using namespace std;
char a[101][101];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
        scanf("%s",a[i]);
	}
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
            if(a[i][j]=='*')printf("*");
            else
			{
				int ans=0;
                if(a[i][j-1]=='*')ans++;
                if(a[i][j+1]=='*')ans++;
                if(a[i+1][j]=='*')ans++;
                if(a[i-1][j]=='*')ans++;
                if(a[i+1][j+1]=='*')ans++;
                if(a[i+1][j-1]=='*')ans++;
                if(a[i-1][j+1]=='*')ans++;
                if(a[i-1][j-1]=='*')ans++;
                printf("%d",ans);
			}
		}
		printf("\n");
	}
    return 0;
}

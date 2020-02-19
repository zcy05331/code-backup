#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int x,y,z;
    int ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
        if(x+y+z>=2)ans++;
	}
    printf("%d",ans);
    return 0;
}

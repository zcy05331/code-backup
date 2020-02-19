#include<bits/stdc++.h>
using namespace std;
int a[10010];
int l,n;
int x,y,z;
int ans=0,num=0;
int main()
{
    //string s[100010];
    scanf("%d%d",&l,&n);
    for(int i=0; i<=l; i++)
        a[i]=2;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x==0)
        {
            for(int i=y; i<=z; i++)
            {
                if(a[i]==1)
                    ans++;
                a[i]=0;
            }
        }
        else
        {
            for(int i=y; i<=z; i++)
            {
                if(!a[i])
                    a[i]=1;
            }
        }
    }
    for(int i=0; i<=l; i++)
    {
        printf("%d ",a[i]);
        if(a[i]==1)
            num++;
    }
    printf("%d\n%d\n",num,ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[101], odd[101], even[101];
int x[101],num;
int main()
{
    int n, k;
    scanf( "%d%d", &n, &k );
    for( int i=1; i<=n; i++ )
    {
        scanf( "%d", &a[i] );
        odd[i]=odd[i-1]+bool( a[i]%2==1 );
        even[i]=even[i-1]+bool( a[i]%2==0 );
    }
    for( int i=2; i<n; i++ )
    {
        if( odd[i]==even[i] )
        {
            x[num++]=abs(a[i]-a[i+1]);
            //printf("%d %d %d\n",i,a[i],a[i+1]);
        }
    }
    int ans=0;
    sort(x,x+num);
    for(int i=0;i<num;i++)
	{
        if(k>=x[i])
		{
			k-=x[i];
            ans++;
		}
		else break;
	}
	printf("%d",ans);
    return 0;
}


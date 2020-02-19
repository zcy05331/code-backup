#include<bits/stdc++.h>
using namespace std;
pair<long long,long long>a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        scanf("%d%d",&a[i].first,&a[i].second);
	}
	sort(a,a+n);

    return 0;
}

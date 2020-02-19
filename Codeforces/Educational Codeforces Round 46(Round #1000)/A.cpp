#include<bits/stdc++.h>
using namespace std;
map<string,int>s1,s2;
string a[105], b[105];
string x[]= {"M", "S", "L", "XL", "XXL", "XXXL", "XS", "XXS", "XXXS"};
int main()
{
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<8;i++)
	{
        s1[x[i]]=s2[x[i]]=0;
	}
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
        s1[a[i]]++;
    }
    for(int i=0;i<n;i++)
	{
		cin>>b[i];
		s2[b[i]]++;
	}
    for(int i=0;i<=8;i++)
	{
       ans+=max(s1[x[i]]-s2[x[i]],0);
	}
	printf("%d",ans);
    return 0;
}

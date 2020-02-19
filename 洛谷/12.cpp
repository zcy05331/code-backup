#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	getline(cin,b);
	getline(cin,a);
	int lena=a.size(),lenb=b.size(),pos=0,anspos=0,ans=0;
	for(int i=0;i<lena;i++)if(a[i]>='A'&&a[i]<='Z')a[i]+=('a'-'A');
	for(int i=0;i<lenb;i++)if(b[i]>='A'&&b[i]<='Z')b[i]+=('a'-'A');
	for(int i=0;i<lena;i++)
	{
		if(a.substr(i,lenb)==b&&(a[i-1]==' '||i==0)&&(a[i+lenb]==' '||i==lena-1))
		{
			if(ans==0)
			{
				anspos=i;
				pos=i;
				ans++;
			}
			else
			{
				pos=i;
				ans++;
			}
		}
	}
	if(ans==0)
	{
		cout<<"-1";
		return 0;
	}
	printf("%d %d",ans,anspos);
	return 0;
}


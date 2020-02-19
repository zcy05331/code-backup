#include<bits/stdc++.h>
using namespace std;
const  unsigned long long mod=212370440130137957ull;
const  unsigned long long mmp=1007;
map<unsigned long long,unsigned long long>hash;
char a[2000];
unsigned long long hashs()
{
	int len=strlen(a);
	unsigned long long ans=0;
	for(int i=0;i<len;i++)
	{
		ans=(ans*mmp+a[i])%mod;
	}
	return ans;
 } 
int main()
{
	int n;
	unsigned long long x=0,ans=0;	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		x=hashs();
		if(hash[x]==0)
		{
			hash[x]++;
			ans++;
		} 
	}
	printf("%lld",ans);
	return 0;
}


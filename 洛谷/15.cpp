#include<bits/stdc++.h>
using namespace std;
char a[1000]= {};
map <char,int> str;
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	int maxn=-1,minn=1000;
	for(int i=0; i<len; i++)
	{
		str[a[i]]++;
	}
	for(char i='a'; i<='z'; i++)
	{
		if(str[i]>maxn)
		{
			maxn=str[i];
		}
		if(str[i]<minn&&str[i]>0)
		{
			minn=str[i];
		}
	}
	int lucky=(maxn-minn);
	if(lucky<2)
	{
		cout<<"No Answer\n0";
		return 0;
	}
	for(int i=2; i<lucky; i++)
	{
		if(!lucky%i)
		{
			cout<<"No Answer\n0";
			return 0;
		}
	}
	cout<<"Lucky Word\n";
	cout<<lucky;
	return 0;
}


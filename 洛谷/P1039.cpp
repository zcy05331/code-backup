#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map<string,int> name;
string s,ss;
string names[25];
string testimony[25][105];
int num[25];
int n,m,p;
bool crap(string tmp)
{
	if(tmp==" I am guilty.") return 0;
	if(tmp==" I am not guilty.") return 0;
	if(tmp==" Today is Monday.") return 0;
	if(tmp==" Today is Tuesday.") return 0;
	if(tmp==" Today is Wednesday.") return 0;
	if(tmp==" Today is Thursday.") return 0;
	if(tmp==" Today is Friday.") return 0;
	if(tmp==" Today is Saturday.") return 0;
	if(tmp==" Today is Sunday.") return 0;
	for(int i=1; i<=m; i++)
		if(tmp==" "+names[i]+" is guilty."||tmp==" "+names[i]+" is not guilty.") return 0;
	return 1;
}
bool judge(int guilty,int day)
{
	int ans;
	for(int i=1; i<=m; i++)
	{
		ans=0;
		for(int j=1; j<=num[i]; j++)
		{
			if(testimony[i][j]==" I am guilty."&&guilty!=i)
			{
				ans++;
			}
			if(testimony[i][j]==" I am not guilty."&&guilty==i)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Monday."&&day!=1)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Tuesday."&&day!=2)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Wednesday."&&day!=3)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Thursday."&&day!=4)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Friday."&&day!=5)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Saturday."&&day!=6)
			{
				ans++;
			}
			if(testimony[i][j]==" Today is Sunday."&&day!=7)
			{
				ans++;
			}
			for(int k=1; k<=m; k++)
			{
				if(testimony[i][j]==" "+names[k]+" is guilty."&&guilty!=k)
				{
					ans++;
				}
				if(testimony[i][j]==" "+names[k]+" is not guilty."&&guilty==k)
				{
					ans++;
				}
			}
		}
		if(ans!=num[i]&&ans!=0) return 0;
	}
	return 1;
}
int check(int guilty,int day)
{
	int ans=0;
	bool twice;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=num[i]; j++)
		{
			twice=0;
			if(testimony[i][j]==" I am guilty."&&guilty!=i)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" I am not guilty."&&guilty==i)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Monday."&&day!=1)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Tuesday."&&day!=2)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Wednesday."&&day!=3)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Thursday."&&day!=4)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Friday."&&day!=5)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Saturday."&&day!=6)
			{
				ans++;
				break;
			}
			if(testimony[i][j]==" Today is Sunday."&&day!=7)
			{
				ans++;
				break;
			}
			for(int k=1; k<=m; k++)
			{
				if(testimony[i][j]==" "+names[k]+" is guilty."&&guilty!=k)
				{
					ans++;
					twice=1;
					break;
				}
				if(testimony[i][j]==" "+names[k]+" is not guilty."&&guilty==k)
				{
					ans++;
					twice=1;
					break;
				}
			}
			if(twice==1) break;
		}
	if(ans!=n)
		for(int i=1; i<=m; i++)
		{
			if(num[i]==0) ans++;
			if(ans==n) break;
		}
	return ans;
}
int read()
{
	char c=getchar();
	int ans=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-48;
		c=getchar();
	}
	return ans;
}
string gl()
{
	string sss,c;
	do
	{
		cin>>c;
		sss=sss+" "+c;
	}
	while(c[c.size()-1]!='.'&&c[c.size()-1]!='?'&&c[c.size()-1]!='!'&&c[c.size()-1]!=',');
	return sss;
}
int main()
{
	m=read();
	n=read();
	p=read();
	for(int i=1; i<=m; i++)
	{
		cin>>s;
		name[s]=i;
		names[i]=s;
	}
	for(int i=1; i<=p; i++)
	{
		cin>>s;
		s=s.substr(0,s.size()-1);
		ss=gl();
		if(crap(ss)) continue;
		num[name[s]]++;
		testimony[name[s]][num[name[s]]]=ss;
	}
	int flag=0;
	for(int i=1; i<=m; i++)
		for(int j=1; j<=7; j++)
			if(check(i,j)==n&&judge(i,j))
			{
				if(flag!=0)
				{
					cout<<"Cannot Determine"<<endl;
					return 0;
				}
				else
				{
					flag=i;
					break;
				}
			}
	if(flag==0) cout<<"Impossible"<<endl;
	else cout<<names[flag]<<endl;
	return 0;
}

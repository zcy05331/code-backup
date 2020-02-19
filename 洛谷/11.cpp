#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100]={},b[100]={};
	int ans1=1,ans2=1;
	scanf("%s%s",a,b);
	int len1=strlen(a),len2=strlen(b);
	for(int i=0;i<len1;i++)
	{
		ans1*=(a[i]-'A'+1);
	}
	for(int i=0;i<len2;i++)
	{
		ans2*=(b[i]-'A'+1);
	}
	if(ans1%47==ans2%47)cout<<"GO";
	else cout<<"STAY";
	return 0;
}


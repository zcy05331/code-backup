#include<bits/stdc++.h>
using namespace std;
string s;
stack<long long>st;
int isnum(char x)
{
    if(x<='9'&&x>='0')return 1;
    return 0;
}
int main()
{
	//freopen("P1981.out","w",stdout);
    cin>>s;
    s+='+';
    int len=s.length();
    long long  tmp=0,now=1;
    for(int i=0;i<len;i++)
	{
        if(isnum(s[i]))
		{
            tmp=tmp*10+s[i]-'0';
            tmp%=10000;
		}
		else if(s[i]=='*')
		{
            now=now*(tmp%10000);
            now%=10000;
            tmp=0;
		}
		else if(s[i]=='+')
		{
            st.push((now*(tmp%10000))%10000);
            tmp=0;
            now=1;
		}
	}
	long long ans=0;
    while(!st.empty())
	{
        ans+=st.top();
        ans%=10000;
       // printf("%d\n",st.top());
        st.pop();
	}
	ans%=10000;
	if(ans<0)ans+=10000;
	printf("%d",ans);
    return 0;
}

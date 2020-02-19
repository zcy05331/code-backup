#include<bits/stdc++.h>
using namespace std;
char a[100]={};
int main()
{
    scanf("%s",a);
    int len=strlen(a),ans=0,now=0;
    for(int i=0;i<9;now++)
    {
        if(a[now]!='-'&&a[now]!='\0'&&a[now]!='X')
        {
            ans+=(a[now]-'0')*(i+1);
            i++;
        }
        else if(a[now]=='X')
        {
        	ans+=10*(i++);
		}
        
    }
    ans%=11;
    if(ans==10)ans='X'-'0';
    if(ans==(a[12]-'0'))puts("Right");
    else 
    {
        a[12]=(ans+'0');
        printf("%s",a);
    }
    return 0;
}

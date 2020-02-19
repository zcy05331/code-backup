#include<bits/stdc++.h>
using namespace std;
stack<char>a;
int main()
{
	char x;
	scanf("%c",&x);
	while(x!='@')
	{
		if(x=='(')a.push('(');
		if(x==')'&&!a.empty())a.pop();
		else if(x==')')
		{
			printf("NO");
			return 0;
		}
		scanf("%c",&x);
	}
	if(!a.empty())printf("NO");
	else printf("YES"); 
	return 0;
}


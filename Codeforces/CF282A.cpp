#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
	{
        string a;
        cin>>a;
        if(a=="X++"||a=="++X")x++;
        else x--;
	}
	printf("%d",x);
    return 0;
}

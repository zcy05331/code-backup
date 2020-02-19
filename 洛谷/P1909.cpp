#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	int minn=2147483647,num,p;
	scanf("%d",&x);
	for(int i=1;i<=3;i++)
	{
		scanf("%d%d",&num,&p);
        int price=(int(x/num)+bool(x%num!=0))*p;
        if(price<minn)minn=price;
	}
	printf("%d",minn);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0,k;
	float sum=0;
	cin>>k;
	while(sum<=k)
	{
		n++;
		sum+=1.0/n;
	}
	cout<<n;
	return 0;
}


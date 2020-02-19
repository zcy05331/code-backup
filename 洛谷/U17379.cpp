#include<bits/stdc++.h>
using namespace std;
long long slove(double n)
{
	if(n<=4)return 2;
	if(n>4&&fmod(n,3.00000000001))return slove(n/3)+1;
	else if(n>4)return slove(n/3+1)+1;
}
int main()
{
	double n;
	scanf("%lf",&n);
	printf("%lld",slove(n);
	return 0;
}


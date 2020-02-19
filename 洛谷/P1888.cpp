#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	for(int i=0;i<3;i++)scanf("%d",&a[i]);
	sort(a,a+3);
	printf("%d/%d",a[0]/__gcd(a[0],a[2]),a[2]/__gcd(a[0],a[2]));
	return 0;
}


#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<string>
using namespace std;
int main()
{
	register long double a=0;
	register long double ans=0;
	while(scanf("%Lf",&a)!=EOF)
	{
		ans+=a*1000000;
	}
	printf("%0.5Lf",ans/1000000);
	return 0;
}


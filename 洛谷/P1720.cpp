#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%0.2f",(pow((1+sqrt(5))/2.0,n)-pow((1-sqrt(5))/2.0,n))/sqrt(5));
	return 0;
}


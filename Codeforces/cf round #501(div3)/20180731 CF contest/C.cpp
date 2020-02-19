#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long a[100005];

int main() {
	long long n,m,x,y,sumx=0;
	scanf("%lld%lld",&n,&m);
	for (register long long i=1;i<=n;++i) {
		scanf("%lld%lld",&x,&y);
		sumx+=x;
		a[i]=x-y;
	}
	sumx-=m;
	sort(a+1,a+n+1);
	if (sumx<=0) {
		puts("0");
		return 0;
	}
	for (register long long i=n;i>=1;--i) {
		sumx-=a[i];
		if (sumx<=0) {
			printf("%lld",n-i+1);
			return 0;
		}
	}
	puts("-1");
	return 0;
}

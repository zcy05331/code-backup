#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n,m,l,r,ans=0;
	bool map[105]={};
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) {
		scanf("%d%d",&l,&r);
		for (int j=l;j<=r;++j) {
			map[j]=true;
		}
	}
	for (int i=1;i<=m;++i) {
		ans+=(1-map[i]);
	}
	printf("%d\n",ans);
	for (int i=1;i<=m;++i) {
		if (!map[i]) {
			printf("%d ",i);
		}
	}
	return 0;
}

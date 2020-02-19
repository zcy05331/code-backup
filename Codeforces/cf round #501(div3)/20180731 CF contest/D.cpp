#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	long long n,k,s,cur=1;
	scanf("%lld%lld%lld",&n,&k,&s);
	if ((n-1)*k>=s&&k<=s) {
		puts("YES");
		s-=k;
		while (s>=n-1) {
			if (cur==1) {
				printf("%lld ",n);
				cur=n;
			}
			else {
				printf("1 ");
				cur=1;
			}
			s-=(n-2);
			--k;
		}
		if (k==1) {
			if (cur==1) {
				printf("%lld",s+2);
			}
			else {
				printf("%lld",n-s-1);
			}
			return 0;
		}
		if (s==0) {
			while (k>0) {	
				if (cur==1) {
					printf("2 ");
					cur=2;
				}
				else {
					printf("1 ");
					cur=1;
				}
				--k;
			}
		}
		else if (cur==1) {
			printf("%lld %lld ",(s+2)/2+2,(s+2)/2+2-(s+1)/2);
			--k;
			--k;
			cur=(s+2)/2+2-(s+1)/2;
			while (k>0) {
				if (cur>1) {
					printf("%lld ",cur-1);
					--cur;
				}
				else {
					printf("%lld ",cur+1);
					++cur;
				}
				--k;
			}
		}
		else {
			printf("%lld %lld ",n-(s+2)/2-1,n-(s+2)/2-1+(s+1)/2);
			--k;
			--k;
			cur=n-(s+2)/2-1+(s+1)/2;
			while (k>0) {
				if (cur>1) {
					printf("%lld ",cur-1);
					--cur;
				}
				else {
					printf("%lld ",cur+1);
					++cur;
				}
				--k;
			}
		}
	}
	else {
		puts("NO");
	}
}

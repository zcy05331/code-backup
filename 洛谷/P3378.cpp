#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue <int> heap;
int main()
{
	int n;
	int tmp,x;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{

		scanf("%d",&tmp);
		if(tmp==1) scanf("%d",&x),heap.push(-x);
		if(tmp==2) printf("%d\n",-heap.top());
		if(tmp==3) heap.pop();
	}
	return 0;
}

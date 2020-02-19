#include<bits/stdc++.h>

const int MaxN = 100010;

struct node
{
	long long h;
	int sp;
	node (long long h,int id):h(h),sp(id){}
};

long long h[MaxN];
int n;

long long slove()
{
    long long ans = 0,now;
    std::stack<node> s;
    s.push(node(-1, 0));
    for(int i = 1; i <= n + 1; i++)
	{
        if(i == n + 1)now = 0;
        else now = h[i];
        node t(now, i);
        while(s.top().h > now)
		{
			t = s.top();
            s.pop();
            ans = std::max(ans, (i - t.sp) * t.h);
		}
		s.push(node(now, t.sp));
	}
	return ans;
}
int main()
{
	while(scanf("%d",&n) && n)
    {
        for(int i = 1; i <= n; i++)
		{
            scanf("%lld",&h[i]);
		}
        printf("%lld\n", slove());
    }
    return 0;
}

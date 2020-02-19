#include <bits/stdc++.h>

const int MaxN = 2000010;
int a[MaxN];
std::deque<int> dq;

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    puts("0");
    for(int i = 1; i < n; i++)
    {
        while(!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        while(!dq.empty() && dq.front() < i - m + 1)
            dq.pop_front();
        dq.push_back(i);
        printf("%d\n",a[dq.front()]);
    }
    return 0;
}
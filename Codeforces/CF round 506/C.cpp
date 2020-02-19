#include <bits/stdc++.h>
const int MaxN = 300010;
int n;
int l[MaxN], r[MaxN];
int lid[MaxN], rid[MaxN];
inline bool cmp1(int a, int b) { return l[a] < l[b]; }
inline bool cmp2(int a, int b) { return r[a] < r[b]; }
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        lid[i] = rid[i] = i;
    }
    std::sort(lid + 1, lid + n + 1, cmp1);
    std::sort(rid + 1, rid + n + 1, cmp2);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int L = l[lid[n]], R = r[rid[1]];
        if (rid[1] == i)
            R = r[rid[2]];
        if (lid[n] == i)
            L = l[lid[n - 1]];
        ans = std::max(ans, R - L);
    }
    printf("%d", ans);
    return 0;
}

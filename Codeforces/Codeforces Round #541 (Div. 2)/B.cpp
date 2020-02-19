#include <bits/stdc++.h>
const int MaxN = 1e5 + 10;
struct node
{
    int x, y;
    bool friend operator<(node t1, node t2)
    {
        if (t1.x != t2.x)
            return t1.x < t2.x;
        return t1.y < t2.y;
    }
} q[MaxN];
int main()
{
    int n;
    scanf("%d", &n);
    q[0].x = 0, q[0].y = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &q[i].x, &q[i].y);
    }
    std::sort(q + 1, q + n + 1);
    int ans = 0;
    int t1 = -1, t2 = -1;
    for (int i = 1; i <= n; i++)
    {
        int tmp = std::max(0, std::min(q[i].x, q[i].y) + 1 - t1 - (t1 == t2));
        ans += tmp;
        t1 = std::max(q[i].x, q[i].y);
        t2 = std::min(q[i].x, q[i].y);
    }
    printf("%d\n", ans);
}
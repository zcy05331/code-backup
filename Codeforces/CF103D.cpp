#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 3e5 + 10;
int n, m, a[MaxN];
ll sum[MaxN], ans[MaxN];
struct node
{
    int a, b, id;
} q[MaxN];

inline bool cmp(node a, node b) { return (a.b == b.b) ? (a.a > b.a) : (a.b < b.b); }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int size = (sqrt(n) + 0.5);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &q[i].a, &q[i].b), q[i].id = i;
    std::sort(q + 1, q + m + 1, cmp);
    int last = n;
    for (int i = 1; i <= m; i++)
    {
        ll ret = 0;
        if (q[i].b >= size)
        {
            for (int j = q[i].a; j <= n; j += q[i].b)
                ret += a[j];
        }
        else
        {
            int a_ = q[i].a, b = q[i].b;
            if (q[i].b != q[i - 1].b)
                last = n;
            for (int j = last; j >= a_; j--)
            {
                sum[j] = a[j];
                if (j + b <= n)
                    sum[j] += sum[j + b];
            }
            last = a_ - 1;
            ret = sum[a_];
        }
        ans[q[i].id] = ret;
    }
    for (int i = 1; i <= m; i++)
        printf("%lld\n", ans[i]);
    return 0;
}

#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n;
struct SegmentTree
{
    int cnt, k[MaxN << 2], b[MaxN << 2], tag[MaxN << 2];
    double val(int x, int id) { return k[id] * (x - 1) + b[id]; }
    void insert(double K, double B)
    {
        ++cnt, k[cnt] = K, b[cnt] = B;
        modify(1, 1, MaxN, cnt);
    }
    void modify(int id, int l, int r, int x)
    {
        if (l == r)
        {
            if (val(l, x) > val(l, tag[id]))
                tag[id] = x;
            return;
        }
        int mid = (l + r) >> 1;
        if (k[x] > k[tag[id]])
        {
            if (val(mid, x) > val(mid, tag[id]))
                modify(id << 1, l, mid, tag[id]), tag[id] = x;
            else
                modify(id << 1 | 1, mid + 1, r, x);
        }
        else
        {
            if (val(mid, x) > val(mid, tag[id]))
                modify(id << 1 | 1, mid + 1, r, tag[id]), tag[id] = x;
            else
                modify(id << 1, l, mid, x);
        }
    }
    double query(int id, int l, int r, int x)
    {
        if (l == r)
            return val(l, tag[id]);
        int mid = (l + r) >> 1;
        double ans = val(x, tag[id]);
        if (x <= mid)
            ans = std::max(ans, query(id << 1, l, mid, x));
        else
            ans = std::max(ans, query(id << 1 | 1, mid + 1, r, x));
        return ans;
    }
} T;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'P')
        {
            double k, b;
            scanf("%lf%lf", &b, &k);
            T.insert(k, b);
        }
        else
        {
            int x;
            double ans;
            scanf("%d", x), ans = T.query(1, 1, MaxN, x);
            printf("%d\n", (int)ans / 100);
        }
    }
    return 0;
}

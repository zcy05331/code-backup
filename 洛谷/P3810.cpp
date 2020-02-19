#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))

const int MaxN = 200010;
const int MaxK = 400010;

struct node
{
    int x, y, z, ans, w;
};

struct BIT
{
    int n, c[MaxN];
    void modify(int x, int add)
    {
        while (x <= n)
        {
            c[x] += add;
            x += lowbit(x);
        }
    }
    int query(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += c[x];
            x -= lowbit(x);
        }
        return ans;
    }
} t;

int n, m, k;
int cnt[MaxN];
node a[MaxN], b[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

bool cmp1(node a, node b)
{
    if(a.x == b.x)
    {
        if(a.y == b.y)
            return a.z < b.z;
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmp2(node a, node b)
{
    if(a.y == b.y)
        return a.z < b.z;
    return a.y < b.y;
}

void cdq(int l, int r)
{
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    cdq(mid + 1, r);
    std::sort(a + l, a + mid + 1, cmp2);
    std::sort(a + mid + 1, a + r + 1, cmp2);
    int j = l;
    for(int i = mid + 1; i <= r; i++)
    {
        while(a[j].y <= a[i].y && j <= mid)
            t.modify(a[j].z, a[j].w), j++;
        a[i].ans += t.query(a[i].z);
    } 
    for(int i = l; i < j; i++)
        t.modify(a[i].z, -a[i].w);
}

int main()
{   
    m = read(), k = read();
    t.n = k;
    for(int i = 1; i <= m; i++)
        b[i].x = read(), b[i].y = read(), b[i].z = read();
    std::sort(b + 1, b + m + 1, cmp1);
    int c = 0;
    for(int i = 1; i <= m; i++)
    {
        ++c;
        if(b[i].x != b[i + 1].x || b[i].y != b[i + 1].y || b[i].z != b[i + 1].z)
            ++n, a[n] = b[i], a[n].w = c, c = 0;
    }
    cdq(1, n);
    for(int i = 1; i <= n; i++)
        cnt[a[i].ans + a[i].w - 1] += a[i].w;
    for(int i = 0; i < m; i++)
        printf("%d\n", cnt[i]);
    return 0;
}

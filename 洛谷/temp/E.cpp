#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    int fa, val;
    std::vector<int> son;
};

node t[MaxN];
int n, p, q, siz, size;
int a[MaxN], b[MaxN], k[MaxN], tmp[MaxN];

void gcd(unsigned a, unsigned b)
{
    if (a == b) return;
    k[++size] = (b - 1) / a;
    gcd(b - k[size] * a, a);
}

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

int solve(int cur)
{
    R int ans, res = 0;
    if (!t[cur].son.size()) return p;
    for (R unsigned i = 0; i < t[cur].son.size(); ++i)
        tmp[i + 1] = t[t[cur].son[i]].val;
    std::sort(tmp + 1, tmp + t[cur].son.size() + 1);
    ans = p * (tmp[t[cur].son.size()] + 1);
    if (tmp[1] > 1) ans = std::min(ans, p + p + q);
    for (R unsigned i = 0; i < t[cur].son.size(); ++i)
    {
        ans = std::min(ans, t[t[cur].son[i]].val * p + q + solve(t[cur].son[i]));
        if (!res && tmp[i + 1] != i + 1) res = i + 1;
    }
    if (res && tmp[1] == 1) ans = std::min(ans, (res + 1) * p + q);
    return ans;
}

void insert()
{
    int cur = 0, flag = false;
    for (R unsigned i = 1; i <= size; ++i)
    {
        if (flag == true)
        {
            t[cur].son.push_back(++siz);
            t[siz].fa = cur, cur = siz, t[cur].val = k[i];
        }
        else
        {
            int j;
            flag = true;
            for (j = 0; j < t[cur].son.size(); j++)
            {
                if (t[t[cur].son[j]].val == k[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                t[cur].son.push_back(++siz);
                t[siz].fa = cur, cur = siz, t[cur].val = k[i];
            }
            else
                cur = t[cur].son[j];
        }
    }
}

int main()
{
    n = read(), p = read(), q = read();
    if (n > 1000)
    {
        int ans = 0;
        for (R unsigned i = 1; i <= n; ++i)
        {
            int a, b;
            a = read(), b = read();
            ans = std::max(ans, b / a);
        }
        return 0 * printf("%d\n", ans);
    }
    for (R unsigned i = 1; i <= n; ++i)
    {
        a[i] = read(), b[i] = read();
        size = 0, b[i] += a[i];
        gcd(a[i], b[i]), insert();
    }
    printf("%d\n", solve(0) - p);
    return 0;
}
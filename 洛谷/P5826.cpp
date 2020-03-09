#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;

int tp, n, m, q;
int a[MaxN], b[MaxN];
std::vector<int> pos[MaxN];

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

int main()
{
    tp = read(), n = read(), q = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        pos[a[i]].push_back(i);
    while (q--)
    {
        int l = read();
        for (int i = 1; i <= l; i++)
            b[i] = read();
        int flag = 1, now = 0;
        for (int i = 1; i <= l; i++)
        {
            std::vector<int>::iterator it = std::upper_bound(pos[b[i]].begin(), pos[b[i]].end(), now);
            if(it == pos[b[i]].end()) {flag = 0; break;}
            now = *it;
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}

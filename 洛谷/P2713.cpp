#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e6 + 10;

struct node
{
    int ch[2];
    int val, dep;
};

node t[MaxN];
int n, m, f[MaxN], ok[MaxN];

int getf(int x)
{
    if (x != f[x])
        f[x] = getf(f[x]);
    return f[x];
}

char get()
{
    char ch = getchar();
    while (!isalpha(ch))
        ch = getchar();
    return ch;
}

int merge(int x, int y)
{
    if (!x || !y) return x | y;
    if (t[x].val > t[y].val) std::swap(x, y);
    t[x].ch[1] = merge(t[x].ch[1], y);
    if (t[t[x].ch[1]].dep > t[t[x].ch[0]].dep)
        std::swap(t[x].ch[1], t[x].ch[0]);
    t[x].dep = t[t[x].ch[1]].dep + 1;
    return x;
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

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        t[i].val = read(), f[i] = i;
    m = read();
    while (m--)
    {
        char op = get();
        if (op == 'M')
        {
            int x = read(), y = read();
            int fx = getf(x), fy = getf(y);
            if (ok[x] || ok[y] || fx == fy)
                continue;
            f[fx] = f[fy] = merge(fx, fy);
        }
        else
        {
            int x = read();
            if (!ok[x])
            {
                x = getf(x), ok[x] = 1;
                f[x] = f[t[x].ch[0]] = f[t[x].ch[1]] = merge(t[x].ch[0], t[x].ch[1]);
                printf("%d\n", t[x].val);
            }
            else
                printf("0\n");
        }
    }
    return 0;
}

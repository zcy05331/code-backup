#include <bits/stdc++.h>

const int MaxN = 100010;

int n, m, p, x;
int a[MaxN], ans;
int f[MaxN], v[MaxN];
int pre[MaxN], nxt[MaxN];

void up(int p)
{
    while (p > 1)
        if (a[f[p]] < a[f[p >> 1]])
        {
            std::swap(f[p], f[p >> 1]);
            std::swap(v[f[p]], v[f[p >> 1]]);
            p >>= 1;
        }
        else
            break;
}

void down(int l, int r)
{
    int t = 2 * l;
    while (t <= r)
    {
        if (t < r && a[f[t]] > a[f[t + 1]])
            t++;
        if (a[f[l]] > a[f[t]])
        {
            std::swap(f[l], f[t]);
            std::swap(v[f[l]], v[f[t]]);
            l = t;
            t = 2 * l;
        }
        else
            break;
    }
}

void insert(int x)
{
    f[++p] = x;
    v[x] = p;
    up(p);
}

void erase(int x)
{
    f[v[x]] = f[p];
    v[f[p]] = v[x];
    p--;
    up(v[x]), down(v[x], p);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i + 1] - a[i];
        nxt[i] = i + 1, pre[i + 1] = i;
        insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        x = f[1];
        ans += a[x];
        if (pre[x] == 0 && nxt[x] == n)
            break;
        if (pre[x] == 0)
        {
            erase(x), erase(nxt[x]);
            pre[nxt[nxt[x]]] = 0;
        }
        else if (nxt[x] == n)
        {
            erase(x), erase(pre[x]);
            nxt[pre[pre[x]]] = n;
        }
        else
        {
            erase(x), erase(pre[x]), erase(nxt[x]);
            a[x] = a[pre[x]] + a[nxt[x]] - a[x];
            insert(x);
            pre[x] = pre[pre[x]];
            nxt[pre[x]] = x;
            nxt[x] = nxt[nxt[x]];
            pre[nxt[x]] = x;
        }
    }
    printf("%d\n", ans);
    return 0;
}
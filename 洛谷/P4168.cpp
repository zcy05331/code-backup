#include <bits/stdc++.h>

const int MaxN = 40010;

int len;

int n, m, l, t;

int L, R;

int st[40], ed[40];

int vec[MaxN], vec2[MaxN];

int a[MaxN];

int val[MaxN];

int num[MaxN];

int c, mod;

int cnt[40][40][MaxN];

int appnum[40][40], mode[40][40];

void unique()
{
    memcpy(vec, a, sizeof(a));
    std::sort(vec + 1, vec + n + 1);
    for (int i = 1; i <= n; i++)
        if (i == 1 || vec[i] != vec[i - 1])
            val[++len] = vec[i];
    for (int i = 1; i <= n; i++)
        num[i] = std::lower_bound(val + 1, val + len + 1, a[i]) - val;
}

void prework()
{
    t = (int)pow(n * 1.0, 1.0 / 3);
    if (t)
        l = n / t;
    for (int i = 1; i <= t; i++)
        st[i] = (i - 1) * l + 1, ed[i] = i * l;
    if (ed[t] < n)
        st[t + 1] = ed[t] + 1, ed[++t] = n;
    for (int i = 1; i <= t; i++)
    {
        for (int j = i; j <= t; j++)
        {
            for (int k = st[i]; k <= ed[j]; k++)
                cnt[i][j][num[k]]++;
            for (int k = 1; k <= len; k++)
                if (cnt[i][j][k] > appnum[i][j] || (cnt[i][j][k] == appnum[i][j] && k < mode[i][j]))
                    appnum[i][j] = cnt[i][j][k], mode[i][j] = k, printf("%d %d %d %d %d\n", i, j, k, appnum[i][j], mode[i][j]);
        }
    }
}

void upd(int x)
{
    cnt[L][R][num[x]]++;
    if (cnt[L][R][num[x]] > c || (cnt[L][R][num[x]] == c && num[x] < mod))
        c = cnt[L][R][num[x]], mod = num[x];
}

int slove(int x, int y)
{
    int l = 0, r = 0;
    for (int i = 1; i <= t; i++)
        if (x <= ed[i])
        {
            l = i;
            break;
        }
    for (int i = t; i; i--)
        if (y >= st[i])
        {
            r = i;
            break;
        }
    if (l + 1 <= r - 1)
        L = l + 1, R = r - 1;
    else
        L = R = 0;
    c = appnum[L][R], mod = mode[L][R];
    if (l == r)
    {
        for (int i = x; i <= y; i++)
            upd(i);
        for (int i = x; i <= y; i++)
            cnt[L][R][num[i]]--;
    }
    else
    {
        for (int i = x; i <= ed[l]; i++)
            upd(i);
        for (int i = st[r]; i <= y; i++)
            upd(i);
        for (int i = x; i <= ed[l]; i++)
            cnt[L][R][num[i]]--;
        for (int i = st[r]; i <= y; i++)
            cnt[L][R][num[i]]--;
    }
    return val[mod];
}

int main()
{
    int lastans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    unique();
    prework();
    for (int i = 1; i <= m; i++)
    {
        int l0, r0, x, y;
        scanf("%d%d", &l0, &r0);
        x = (l0 + lastans - 1) % n + 1, y = (r0 + lastans - 1) % n + 1;
        if (x > y)
            std::swap(x, y);
        lastans = slove(x, y);
        printf("%d\n", lastans);
    }
    return 0;
}
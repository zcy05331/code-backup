#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int base = 3331;
const int MaxN = 1e3 + 10;

int n, m, cnt[MaxN];
int a[MaxN][MaxN], s[MaxN][MaxN];
unsigned h[MaxN][MaxN], pow[MaxN];

unsigned int get(int x, int l, int r){return h[x][r] - h[x][l - 1] * pow[r - l + 1];}

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
    int l = 0, r = 0;
    n = read(), pow[0] = 1;
    for(int i = 1; i <= 2000; i++)
        pow[i] = pow[i - 1] * base + 1;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = read(), r = std::max(r, cnt[i]);
        for (int j = 1; j <= cnt[i]; j++)
            a[i][j] = read();
        for (int j = 1; j < cnt[i]; j++)
            s[i][j] = a[i][j] - a[i][j + 1];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < cnt[i]; j++)
            h[i][j] = h[i][j - 1] * base + s[i][j];
    }
    // while(l < r)
    // {
    //     int mid = (l + r + 1) >> 1;
    //     if(check(mid)) l = mid;
    //     else r = mid - 1;
    // }
    // printf("%d\n", l + 1);
    return 0;
}

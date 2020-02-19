#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxM = 22;
const int MaxN = 5e2 + 10;

char ch[MaxN];
int n, m, f[1 << MaxM], nxt[MaxN][MaxN];

int to(char x) { return x - 'a'; }

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
    int T = read();
    while (T--)
    {
        n = read(), scanf("%s", ch + 1), m = strlen(ch + 1);
        if (n > 21)
        {
            printf("NO\n");
            continue;
        }
        memset(nxt, -1, sizeof(nxt));
        for(int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                nxt[i][j] = nxt[i - 1][j];
                if (j == to(ch[i]))
                    nxt[i][j] = i;
            }
        }
        for(int i = 0; i <= (1 << n); i++)
            f[i] = m;
        for(int i = 1; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (f[i ^ (1 << j)] == -1)
                {
                    f[i] = -1;
                    continue;
                }
                if (i & (1 << j))
                    f[i] = std::min(f[i], nxt[f[i ^ (1 << j)]][j]);
            }
        }
        printf((f[(1 << n) - 1] == -1) ? "NO\n" : "YES\n");
    }
    return 0;
}

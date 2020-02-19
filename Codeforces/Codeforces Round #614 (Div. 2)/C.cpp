#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 2e5 + 10;
const int dx[] = {-1, 0, 1};

int n, q, cnt;
int a[2][MaxN];

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
    n = read(), q = read();
    while (q--)
    {
        int r = read() - 1, c = read();
        if (a[r][c])
        {
            a[r][c] = 0;
            for (int i = 0; i < 3; i++)
                if (a[r ^ 1][c + dx[i]])
                    --cnt;
        }
        else
        {
            a[r][c] = 1;
            for (int i = 0; i < 3; i++)
                if (a[r ^ 1][c + dx[i]])
                    ++cnt;
        }
        printf(cnt ? "No\n" : "Yes\n");
    }
    return 0;
}

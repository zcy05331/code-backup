#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e6 + 10;

int n, m, r, c;
char ch[MaxN];
std::vector<int> a[MaxN], b[MaxN], d[MaxN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%d", &n, &m, &r, &c);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", ch), a[i].clear();
            for (int j = 0; j < m; j++)
                a[i].push_back(ch[j] - '0');
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%s", ch), b[i].clear();
            for (int j = 0; j < m; j++)
                b[i].push_back(ch[j] - '0');
        }
        for (int i = 0; i < n; i++)
        {
            d[i].clear();
            for (int j = 0; j < m; j++)
                if (a[i][j] != b[i][j])
                    d[i].push_back(1);
                else
                    d[i].push_back(0);
        }
    }
    return 0;
}

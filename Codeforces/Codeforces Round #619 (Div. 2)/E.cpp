#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e2 + 10;
const char op[] = {'R', 'G', 'Y', 'B'};

int n, m, q;
char s[MaxN][MaxN];
int f[MaxN][MaxN], sum[MaxN][MaxN][4];

int get(int x1, int y1, int x2, int y2, int col) { return sum[x2][y2][col] - sum[x1 - 1][y2][col] - sum[x2][y1 - 1][col] + sum[x1 - 1][y1 - 1][col]; }

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int k = 0; k < 4; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k] + (s[i][j] == op[k]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] != 'R' || f[i][j])
                continue;
            for (int k = 1; k <= std::min(n - i, m - j); k++)
            {
                if (get(i, j, i + k - 1, j + k - 1, 0) != k * k)
                    continue;
                if (get(i + k, j, i + 2 * k - 1, j + k - 1, 1) != k * k)
                    continue;
                if (get(i, j + k, i + k - 1, j + 2 * k - 1, 2) != k * k)
                    continue;
                if (get(i + k, j + k, i + 2 * k - 1, j + 2 * k - 1, 3) != k * k)
                    continue;
                f[i][j] = k;
                break;
            }
            for (int k = 1; k <= f[i][j] - 1; k++)
                f[i + k][j + k] = f[i][j] - k;
        }
    }
    return 0;
}

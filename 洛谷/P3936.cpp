#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
const int MaxN = 30;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int n, m, c;
int p[51];
int a[MaxN][MaxN], tmp[MaxN][MaxN];
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
inline int calc(int A[30][30])
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k <= 3; k++)
            {
                int nx = i + dx[k], ny = j + dy[k];
                if (A[nx][ny] && (A[nx][ny] != A[i][j]))
                    ++ret;
            }
        }
    }
    return ret / 2;
}
inline void init()
{
    int now = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = now;
            ++cnt;
            if (cnt == p[now])
                cnt = 0, now++;
        }
    }
}
inline void sa()
{
    double t = 1.0, delta;
    if (n * m <= 400)
        delta = 0.9999900001;
    memcpy(tmp, a, sizeof(a));
    while (t > 1e-5)
    {
        std::pair<int, int> pos1, pos2;
        pos1.first = rand() % n + 1;
        pos2.first = rand() % n + 1;
        pos1.second = rand() % m + 1;
        pos2.second = rand() % m + 1;
        while (tmp[pos1.first][pos1.second] == tmp[pos2.first][pos2.second])
        {
            pos1.first = rand() % n + 1;
            pos2.first = rand() % n + 1;
            pos1.second = rand() % m + 1;
            pos2.second = rand() % m + 1;
        }
        std::swap(tmp[pos1.first][pos1.second], tmp[pos2.first][pos2.second]);
        int num = calc(tmp) - calc(a);
        if (num < 0)
            std::swap(a[pos1.first][pos1.second], a[pos2.first][pos2.second]);
        else if (exp(-num / t) * RAND_MAX > rand())
            std::swap(a[pos1.first][pos1.second], a[pos2.first][pos2.second]);
        else
            std::swap(tmp[pos1.first][pos1.second], tmp[pos2.first][pos2.second]);
        t *= delta;
    }
}
int main()
{
    srand(107.7777777);
    n = read(), m = read(), c = read();
    for (int i = 1; i <= c; i++)
        p[i] = read();
    init();
    for (int i = 1; i <= 2; i++)
        sa();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}

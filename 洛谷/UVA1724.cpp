#include <bits/stdc++.h>

#define R register
#define ll long long
#define pair std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
#define checkpos(i, j) (i > 0 && i < 9 && j > 0 && j < 9)

const int mod = 998244353;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int x[5], y[5], ans;
int a[10][10], b[10][10], tmp[10][10];
std::map<ll, int> m;

ll change(int x[10][10])
{
    ll s = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            s = (s * 233 + x[i][j]) % mod;
    return s;
}

inline void print(int x[10][10])
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
            printf("%d ", x[i][j]);
        puts("");
    }
    puts("");
}

inline void dfsa(int dep)
{
    int ch = change(tmp);
    if (!m[ch])
    {
        m[ch] = 1;
        //printf("%d\n", dep);
        //print(tmp);
    }
    if (dep > 4)
        return;
    int cnt = 0;
    std::vector<pair> X, Y;
    for (int i = 1; i <= 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            int ex = x[i] + dx[k], ey = y[i] + dy[k];
            if (!checkpos(ex, ey))
                continue;
            if (tmp[ex][ey])
                ex = ex + dx[k], ey = ey + dy[k];
            if (!checkpos(ex, ey))
                continue;
            if (tmp[ex][ey])
                continue;
            X.push_back(mp(ex, ey)), Y.push_back(mp(x[i], y[i])), ++cnt;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        x[i] = X[i].first, y[i] = X[i].second;
        dfsa(dep + 1);
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        x[i] = Y[i].first, y[i] = Y[i].second;
    }
}

inline void dfsb(int dep)
{
    ll s = change(tmp);
    if (m[s])
    {
        ans = 1;
        //print(tmp);
    }
    if (dep > 4)
        return;
    int cnt = 0;
    std::vector<pair> X, Y;
    for (int i = 1; i <= 4; i++)
    {
        for (int k = 0; k < 4; k++)
        {
            int ex = x[i] + dx[k], ey = y[i] + dy[k];
            if (!checkpos(ex, ey))
                continue;
            if (tmp[ex][ey])
                ex = ex + dx[k], ey = ey + dy[k];
            if (!checkpos(ex, ey))
                continue;
            if (tmp[ex][ey])
                continue;
            X.push_back(mp(ex, ey)), Y.push_back(mp(x[i], y[i])), ++cnt;
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        x[i] = X[i].first, y[i] = X[i].second;
        dfsb(dep + 1);
        std::swap(tmp[X[i].first][X[i].second], tmp[Y[i].first][Y[i].second]);
        x[i] = Y[i].first, y[i] = Y[i].second;
    }
}

int main()
{
    //freopen("Z1724.out", "w", stdout);
    int u, v;
    for (int i = 1; i <= 4; i++)
        scanf("%d%d", &u, &v), a[u][v] = 1;
    for (int i = 1; i <= 4; i++)
        scanf("%d%d", &u, &v), b[u][v] = 1;
    m[change(a)] = 1;
    //print(a);
    if (change(a) == change(b))
        ans = 1;
    // if (a[3][3] + a[5][3] + a[6][2] + a[6][6] == 4)
    //     return 0 * printf("YES");
    int cnt = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            tmp[i][j] = a[i][j];
            if (tmp[i][j])
                ++cnt, x[cnt] = i, y[cnt] = j;
        }
    }
    dfsa(1);
    cnt = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            tmp[i][j] = b[i][j];
            if (tmp[i][j])
                ++cnt, x[cnt] = i, y[cnt] = j;
        }
    }
    dfsb(1);
    if (ans)
        printf("YES");
    else
        printf("NO");
    return 0;
}

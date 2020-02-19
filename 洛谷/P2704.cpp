#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 1e3 + 10, MaxM = 20, Max = (1 << 10) + 10;

int n, m;
std::vector<int> vec;
int a[MaxN][MaxM], s[MaxN], sum[Max], ok[Max], f[3][Max][Max];

int count(int x)
{
    int cnt = 0;
    while (x)
        cnt += (x & 1), x >>= 1;
    return cnt;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        std::string str;
        std::cin >> str;
        for (int j = 0; j < m; j++)
            a[i][j + 1] = ((str[j] == 'P') ? 1 : 0), s[i] = (s[i] << 1) + a[i][j + 1];
    }
    for (int i = 0; i < (1 << m); i++)
    {
        sum[i] = count(i);
        if (((i & (i >> 1)) == 0) && ((i & (i >> 2)) == 0) && ((i & (i << 1)) == 0) && ((i & (i << 2)) == 0))
        {
            ok[i] = 1, vec.push_back(i);
            if ((i & s[1]) == i)
                f[1][0][vec.size() - 1] = sum[i];
        }
    }
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size(); j++)
            if (((vec[i] & vec[j]) == 0) && ((vec[i] & s[1]) == vec[i]) && ((vec[j] & s[2]) == vec[j]))
                f[2][i][j] = sum[vec[i]] + sum[vec[j]];
    for (int i = 3; i <= n; i++)
    {
        for (int j = 0; j < vec.size(); j++)
            if ((vec[j] & s[i]) == vec[j])
                for (int k = 0; k < vec.size(); k++)
                    if (((vec[k] & s[i - 1]) == vec[k]) && ((vec[j] & vec[k]) == 0))
                        for (int l = 0; l < vec.size(); l++)
                            if (((vec[l] & s[i - 2]) == vec[l]) && ((vec[j] & vec[l]) == 0) && ((vec[k] & vec[l]) == 0))
                                f[i % 3][k][j] = std::max(f[i % 3][k][j], f[(i - 1) % 3][l][k] + sum[vec[j]]);
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < vec.size(); j++)
            ans = std::max(ans, f[n % 3][i][j]);
    printf("%d\n", ans);
    return 0;
}

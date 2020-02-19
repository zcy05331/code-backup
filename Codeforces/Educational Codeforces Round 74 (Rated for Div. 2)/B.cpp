#include <bits/stdc++.h>

#define ll long long
#define sum(a, b, mod) ((a + b) % mod)

const int MaxN = 2e5 + 10;

int n, q, r;
int a[MaxN];
std::vector<int> vec;

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
    q = read();
    while (q--)
    {
        n = read(), r = read(), vec.clear();
        for (int i = 1; i <= n; i++)
            a[i] = read();
        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
            if (a[i] != a[i - 1])
                vec.push_back(a[i]);
        int L = 0, R = vec.size() - 1, cnt = 0;
        while (L <= R)
        {
            ++cnt;
            while (L <= R && vec[L] <= cnt * r)
                L++;
            R--;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
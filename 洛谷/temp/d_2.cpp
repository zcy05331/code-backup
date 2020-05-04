#include <bits/stdc++.h>

#define ll long long
#define pir std::pair<int, int>
#define mp(i, j) std::make_pair(i, j)
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

int n, q, cnt;
std::vector<int> L, R;

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
    for (int i = 1; i <= q; i++)
    {
        int op = read(), l = read(), r = read();
        if (op == 1)
            L.push_back(l), R.push_back(r);
        else
        {
            int ans = 0;
            for(int j = 0; j < L.size(); j++)
                if(L[j] <= l && r <= R[j]) ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}

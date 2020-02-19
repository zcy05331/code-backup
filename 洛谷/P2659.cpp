#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e6 + 10;

std::vector<int> st;
int n, a[MaxN], l[MaxN], r[MaxN];

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
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    a[0] = a[n + 1] = -1, st.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        while (a[st.back()] >= a[i])
            st.pop_back();
        l[i] = st.back() + 1, st.push_back(i);
    }
    st.clear(), st.push_back(n + 1);
    for (int i = n; i; i--)
    {
        while (a[st.back()] >= a[i])
            st.pop_back();
        r[i] = st.back() - 1, st.push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = std::max(ans, (r[i] - l[i] + 1) * 1ll * a[i]);
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>

const int MaxN = 1e6 + 10;
int l[MaxN], r[MaxN];
long long h[MaxN], v[MaxN];
std::stack<int> st;
long long x[MaxN];
long long ans;

int main()
{
    int n;
    scanf("%d", &n);
    h[0] = 0x7fffffff;
    h[n + 1] = h[0];
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &h[i], &v[i]);
    }
    st.push(0);
    for (int i = 1; i <= n; i++)
    {
        while (h[i] >= h[st.top()])
            st.pop();
        l[i] = st.top();
        st.push(i);
    }
    while (st.size())
        st.pop();
    st.push(n + 1);
    for (int i = n; i >= 1; i--)
    {
        while (h[i] >= h[st.top()])
            st.pop();
        r[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        x[l[i]] += v[i];
        x[r[i]] += v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, x[i]);
    }
    printf("%lld", ans);
    return 0;
}
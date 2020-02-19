#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 3e6 + 10;

std::vector<int> st;
int n, a[MaxN], f[MaxN];

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    st.push_back(n + 1), a[n + 1] = (int)(1e9 + 7);
    for(int i = n; ~i; i--)
    {
        while(!st.empty() && a[st.back()] <= a[i])
            st.pop_back();
        f[i] = st.back(), st.push_back(i);
    }
    for(int i = 1; i <= n; i++)
        printf("%d ", (f[i] > n) ? 0 : f[i]);
    return 0;
}

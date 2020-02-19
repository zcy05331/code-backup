#include <bits/stdc++.h>
#define R register 
const int MaxN = 300010;
const int  Max = 15000000;

int tot;

std::stack<int> st;

std::map<int, bool> used;

int a[MaxN], prime[1000000], fac[Max + 2], vis[Max + 2];

void p()
{
    for(R int i = 2; i <= Max; ++i)
    {
        if(!vis[i])
            prime[++tot] = i, fac[i] = i;
        for(R int j = 1; j <= tot && (prime[j] * i <= Max); ++j)
        {
            vis[i * prime[j]] = true;
            fac[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
                break;
        }
    }
}

int gcd(int a, int b){return (b == 0) ? a : gcd(b, a % b);}

int main()
{
    int n;
    p();
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int flag = 1;
    for (int i = 1; i <= n; i++)
        if (a[1] != a[i])
            flag = 0;
    if (flag)
        return 0 * puts("-1");
    int tmp = a[1], ans = 0x7f7f7f7f;
    for(int i = 2; i <= n; i++)
        tmp = gcd(tmp, a[i]);
    for(int i = 1; i <= n; i++)
        a[i] /= tmp;
    for(int i = 1; i <= n; i++)
    {
        int top = 0;
        int t = a[i];
        while(t != 1)
        {
            if(!used[fac[t]])
                vis[fac[t]]++, used[fac[t]] = 1, st.push(fac[t]);
            t /= fac[t];
        }
        while(!st.empty())
            used[st.top()] = 0, st.pop();
    }
    for(int i = 2; i <= Max; i++)
        ans = std::min(ans, n - vis[i]);
    printf("%d\n", ans);
    return 0;
}
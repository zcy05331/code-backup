# include <bits/stdc++.h>

# define ll long long

const int MaxN = 200010;

int a[MaxN];

ll s[MaxN];

int main()
{
    int ans = 0;
    ll n, k;
    int l = 0x7f7f7f7f, r = 0;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[a[i]]++, r = std::max(r, a[i]), l = std::min(l, a[i]);   
    for(int i = r - 1; i >= 0; i--)
        s[i] += s[i + 1];
    ll sum = 0;
    for(int i = r; i >= l; i-- )
    {
        if(i == l)
            break;
        if(sum + s[i] <= k)
        {
            sum += s[i];
            if(i == l + 1)
            {
                ans++;
                break;
            }
        }
        else
        {
            ans++;
            sum = s[i];
            if(i == l + 1)
            {
                ans++;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
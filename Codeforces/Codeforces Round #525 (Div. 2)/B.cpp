# include <bits/stdc++.h>

# define ll long long

ll a[100010];

int main()
{
    ll n, k;
    ll now = 0, pos = 1;
    scanf("%I64d%I64d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%I64d", &a[i]);
    std::sort(a + 1, a + n + 1);
    a[n + 1] = 0x7f7f7f7f7f7f7f;
    for(int i = 1; i <= k; i++)
    {
        if(pos == n + 1)
        {
            printf("0\n");
            continue;
        }
        printf("%I64d\n", a[pos] - now);
        now += a[pos] - now;
        ll l = pos + 1, r = n + 1;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            if(a[mid] > now)
                r = mid;
            else l = mid + 1;
        }
        pos = l;
    }
    return 0;
}
# include <bits/stdc++.h>

# define ll long long

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        ll l, r;
        ll ans;
        scanf("%I64d%I64d", &l, &r);
        if(l == r)
        {
            printf("%I64d\n", ((l % 2) ? -l : l));
            continue;
        }
        ll x, y;
        ll lodd = ((l % 2 == 1) ? l : l + 1), leven = ((l % 2 == 0) ? l : l + 1), rodd = ((r % 2 == 1) ? r : r - 1), reven = ((r % 2 == 0) ? r : r - 1);
       
        x = ((reven - leven) / 2 + 1) * ((reven + leven) / 2);
        y = ((rodd - lodd) / 2 + 1) * ((rodd + lodd) / 2);
        //printf("%d %d %d %d\n", leven, lodd, reven, rodd);
        ans = x - y;
        printf("%I64d\n", ans);
    }
    return 0;
}
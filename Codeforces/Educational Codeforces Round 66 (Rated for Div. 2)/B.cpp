#include <bits/stdc++.h>

#define R register
#define ll long long
#define cmax(a, b) ((a < b) ? b : a)
#define cmin(a, b) ((a < b) ? a : b)
#define sum(a, b, mod) ((a + b) % mod)
const int MaxN = 1e5 + 10;
ll ans, over[MaxN], st[MaxN];
int main()
{
    int l;
    scanf("%d", &l);
    st[0] = st[1] = 1;
    for (int i = 1; i <= l; i++)
    {
        std::string op;
        std::cin >> op;
        if (op == "add")
        {
            if (over[st[0]])
                return 0 * printf("OVERFLOW!!!");
            ans += st[st[0]];
        }
        else if (op == "end")
        {
            over[st[0]--] = false;
        }
        else if (op == "for")
        {
            ll x;
            scanf("%I64d", &x);
            ++st[0];
            over[st[0]] |= over[st[0] - 1];
            if (!over[st[0]])
                st[st[0]] = 1ll * x * st[st[0] - 1];
            if (st[st[0]] > ((1ll << 32) - 1ll))
                over[st[0]] = true;
        }
    }
    if (ans > ((1ll << 32) - 1ll))
        return 0 * printf("OVERFLOW!!!");

    printf("%I64d\n", ans);
    return 0;
}

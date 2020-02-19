#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)
bool END;
char _B[1 << 16], *_S = _B, *_T = _B, _U[1 << 16 | 1], *_O = _U, *_W = _U + (1 << 16);
#define getc() (_S == _T && (_T = (_S = _B) + fread(_B, 1, 1 << 16, stdin), _S == _T) ? END = 1 : *_S++)
const int MaxN = 1e6 + 10;
int n, ans = 1, a[MaxN];

inline int read()
{
    R int x = 0;
    char ch = getc();
    while (ch > '9' || ch < '0')
        ch = getc();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getc();
    return x;
}

int main()
{
    n = read();
    for (R int i = 1; i <= n; ++i)
        a[i] = read(), (a[i] != a[i - 1]) ? (++ans) : 0;
    printf("%d\n", ans);
    return 0;
}

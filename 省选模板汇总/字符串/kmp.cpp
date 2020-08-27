#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e6 + 10;

int n, m, nxt[MaxN];
char s[MaxN], t[MaxN];

int main()
{   
    int ans = 0;
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 2, j = 0; i <= m; i++)
    {
        while(j && t[j + 1] != t[i]) j = nxt[j];
        if(t[i] == t[j + 1]) ++j;
        nxt[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i++)  
    {
        while(j && t[j + 1] != s[i]) j = nxt[j];
        if(t[j + 1] == s[i]) ++j;
        if(j == m) ans++, j = nxt[j];
    }
    printf("%d\n", ans);
    return 0;
}

#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 5e5 + 10;

char s[MaxN];
int n, m, cnt = 1;
int tag[MaxN], vis[MaxN], ch[MaxN][27];

void insert()
{
    int now = 1, len = strlen(s + 1);
    for(int i = 1; i <= len; i++)
    {
        int c = s[i] - 'a';
        if(ch[now][c])
            now = ch[now][c];
        else 
            ch[now][c] = ++cnt, now = cnt;
        s[i] = 0;
    }
    tag[now] = 1;
}

int query()
{
    int now = 1, len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
    {
        int c = s[i] - 'a';
        if (ch[now][c])
            now = ch[now][c];
        else
            return 0;
    }
    if(!tag[now]) return 0;
    if(vis[now] == 1) return 2;
    else 
    {
        vis[now] = 1;
        return 1;
    }
}

int main()
{   
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%s", s + 1), insert();
    scanf("%d", &m);
    while(m--)
    {
        int ans = 0;
        scanf("%s", s + 1), ans = query();
        if(ans == 0) puts("WRONG");
        else if(ans == 1) puts("OK");
        else puts("REPEAT");
    }
    return 0;
}

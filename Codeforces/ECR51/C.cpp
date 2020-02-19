#include<bits/stdc++.h>

int n;
int a[101];
int s[101];
int ans[101];
int num[101];
std::vector<int> vec;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), s[a[i]]++;
    int cnt = 0, cnt1 = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(s[i] == 1)
            cnt++;
        if(s[i] > 2)
            cnt1++;
    }
    if((cnt) % 2 && !cnt1)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    if(cnt % 2 == 0)
    {
        int cntx = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[a[i]] == 1)
            {
                putchar((cntx % 2) ? 'B' : 'A');
                cntx++;
            }
            else putchar('A');
        }
    }
    else 
    {
        int chk = 0;
        int cnta = 0, cntb = 0;
        for(int i = 1; i <= n; i++)
        {
            if(s[a[i]] == 2)
            {
                putchar('A');
                continue;
            }
            if(s[a[i]] == 1)
            {
                if(cnta < cntb){putchar('A'), cnta++;}
                else {putchar('B'), cntb++;}
            }
            else if(s[a[i]] >= 3 && !chk)
            {
                putchar(cnta < cntb ? 'A' : 'B');
                if(cnta < cntb)cnta++;
                else cntb++;
                chk = 1;
            }   
            else putchar('A');
        }
    }
    return 0;
}
#include<bits/stdc++.h>

int p[1001];
int tag[1001];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        int cur = i;
        memset(tag, 0, sizeof(tag));
        while(tag[cur] < 2)
        {
            tag[cur]++;
            if(tag[cur] == 2)
            {
                printf("%d ", cur);
                break;
            }
            cur = p[cur];
        }
    }
    return 0;
}
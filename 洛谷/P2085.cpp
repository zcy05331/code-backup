#include <bits/stdc++.h>

#define R register
#define ll long long
#define sum(a, b, mod) (((a) + (b)) % mod)

const int MaxN = 1e5 + 10;

struct node
{
    ll id, x, val;
    bool operator<(node x)const{return val > x.val;}
};

int n, m;
ll A[MaxN], B[MaxN], C[MaxN];
std::priority_queue<node> q;

ll f(ll id, ll x){ return A[id] * x * x + B[id] * x + C[id];}

inline int read()
{
    int x = 0;
    char ch = getchar();
    while(ch > '9' || ch < '0')
        ch = getchar();
    while(ch <= '9' && ch >= '0') 
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

int main()
{   
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
        A[i] = read(), B[i] = read(), C[i] = read();
    for(int i = 1; i <= n; i++)
        q.push((node){i, 1, f(i, 1)});
    for(int i = 1; i <= m; i++)
    {
        node x = q.top();
        q.pop(), printf("%lld ", x.val);
        q.push((node){x.id, x.x + 1, f(x.id, x.x + 1)});
    }
    return 0;
}

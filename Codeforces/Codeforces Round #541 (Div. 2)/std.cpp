#include <bits/stdc++.h>
#define lld I64d
using namespace std;
bool Wrong;
inline long long Readin()
{
    long long K = 0, F = 1;
    char C = ' ';
    while (C < '0' or C > '9')
        F = C == '-' ? -1 : 1, C = getchar();
    while (C <= '9' and C >= '0')
        K = (K << 1) + (K << 3) + C - '0', C = getchar();
    return F * K;
}
inline char Getchar()
{
    register char C = getchar();
    while (C == ' ' or C == '\n')
        C = getchar();
    return C;
}
const int MaxN = 2000 + 10;
int N, M;
bool Map[MaxN][MaxN], Equ[MaxN][MaxN], Map2[MaxN][MaxN], Vis[MaxN][MaxN];
int Cnt;
int B[MaxN], Ans[MaxN], Time;
void Dfs(int Nod)
{
    B[Nod] = Cnt;
    for (register int i = 0; ++i <= 2000;)
        if (Equ[Nod][i] and not B[i])
            Dfs(i);
}
int In[MaxN];
queue<int> Q;
int main()
{
    N = Readin();
    M = Readin();
    for (register int i = 0; ++i <= N;)
        for (register int j = 0; ++j <= M;)
        {
            register char T = Getchar();
            Map[i][j + 1000] = T == '<';
            Map[j + 1000][i] = T == '>';
            Equ[i][j + 1000] = Equ[j + 1000][i] = T == '=';
        }
    for (register int i = 0; ++i <= N;)
        if (not B[i])
            ++Cnt, Dfs(i);
    for (register int j = 0; ++j <= M;)
        if (not B[j + 1000])
            ++Cnt, Dfs(j + 1000);
    //	for(register int i = 0 ; ++i <= N ; cout << endl )
    //		for(register int j = 0 ; ++j <= M ; )
    //			printf( "%d " , Map[i][j+1000] ) ;
    //	printf( "Cnt=%d\n" , Cnt ) ;
    for (register int i = 0; ++i <= N;)
        for (register int j = 0; ++j <= M;)
        {
            if (B[i] == B[j + 1000] and not Equ[i][j + 1000])
                return not printf("No\n");
            if (Vis[B[i]][B[j + 1000]] and Map2[B[i]][B[j + 1000]] != Map[i][j + 1000])
                return not printf("No\n");
            Map2[B[i]][B[j + 1000]] = Map[i][j + 1000];
            Map2[B[j + 1000]][B[i]] = Map[j + 1000][i];
            Vis[B[i]][B[j + 1000]] = Vis[B[j + 1000]][B[i]] = 1;
        }
    //	for(register int i = 0 ; ++i <= Cnt ; cout << endl )
    //		for(register int j = 0 ; ++j <= Cnt ; )
    //			printf( "%d " , Map2[i][j] ) ;
    for (register int i = 0; ++i <= Cnt;)
        for (register int j = 0; ++j <= Cnt;)
            if (Map2[i][j])
                ++In[j];
    //	for(register int i = 0 ; ++i <= Cnt ; printf( "%d " , In[i] ) ) ;
    //	printf( "\n" ) ;
    for (register int i = 0; ++i <= Cnt;)
        if (not In[i])
            Q.push(i);
    while (Q.size())
    {
        ++Time;
        for (register int i = Q.size(); i--;)
        {
            register int Nod = Q.front();
            Q.pop();
            Ans[Nod] = Time;
            for (register int j = 0; ++j <= Cnt;)
                if (Map2[Nod][j])
                {
                    --In[j];
                    if (In[j] == 0)
                    {
                        Q.push(j);
                    }
                }
        }
    }
    //	for(register int i = 0 ; ++i <= Cnt ; )
    //		printf( "%d\n" , Ans[i] ) ;
    for (register int i = 0; ++i <= Cnt;)
        if (not Ans[i])
            return not printf("No\n");
    printf("Yes\n");
    for (register int i = 0; ++i <= N;)
        printf("%d ", Ans[B[i]]);
    printf("\n");
    for (register int i = 0; ++i <= M;)
        printf("%d ", Ans[B[i + 1000]]);
    printf("\n");
    return 0;
}
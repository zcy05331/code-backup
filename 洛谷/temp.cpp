#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MaxN = 100000 + 5, MaxM = 200000 + 5;
const int MaxV = 400000 + 5;
const int INF = 0x7F7F7F7F;

struct Matrix
{
    int mat[2][2];

    Matrix()
    {
        memset(mat, -0x3F, sizeof mat);
    }

    inline Matrix operator*(Matrix b)
    {
        Matrix c;

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    c.mat[i][j] = max(c.mat[i][j], mat[i][k] + b.mat[k][j]);

        return c;
    }
};

int N, M;
int cntv, cnte;
int A[MaxN];
int Fa[MaxN], Siz[MaxN], Dep[MaxN], Wson[MaxN];
int Top[MaxN], Id[MaxN], Dfn[MaxN], End[MaxN];
int F[MaxN][2];
int Head[MaxN], To[MaxM], Next[MaxM];
Matrix Val[MaxN];

struct SegTree
{
    int L[MaxV], R[MaxV];
    Matrix M[MaxV];

    inline void Push_up(int i)
    {
        M[i] = M[i << 1] * M[i << 1 | 1];
    }

    void Build_Tree(int left, int right, int i)
    {
        L[i] = left, R[i] = right;
        if (L[i] == R[i])
        {
            M[i] = Val[Dfn[L[i]]];
            return;
        }

        int mid = (L[i] + R[i]) >> 1;
        Build_Tree(L[i], mid, i << 1);
        Build_Tree(mid + 1, R[i], i << 1 | 1);
        Push_up(i);
    }

    void Update_Tree(int x, int i)
    {
        if (L[i] == R[i])
        {
            // 直接赋值，减小常数
            M[i] = Val[Dfn[x]];
            return;
        }

        int mid = (L[i] + R[i]) >> 1;
        if (x <= mid)
            Update_Tree(x, i << 1);
        else
            Update_Tree(x, i << 1 | 1);
        Push_up(i);
    }

    // 查询一个点的 DP 值，相当于查询这条重链上链尾矩阵和链中转移矩阵的 '*' 积
    Matrix Query_Tree(int left, int right, int i)
    {
        if (L[i] == left && R[i] == right) return M[i];

        int mid = (L[i] + R[i]) >> 1;
        if (right <= mid)
            return Query_Tree(left, right, i << 1);
        else if (left > mid)
            return Query_Tree(left, right, i << 1 | 1);
        else
            return Query_Tree(left, mid, i << 1) * Query_Tree(mid + 1, right, i << 1 | 1);
    }
} T;

inline void add_edge(int from, int to)
{
    cnte++;
    To[cnte] = to;
    Next[cnte] = Head[from];
    Head[from] = cnte;
}

void readin()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i < N; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
}

void dfs1(int u)
{
    Siz[u] = 1;

    for (int i = Head[u]; i; i = Next[i])
    {
        int v = To[i];
        if (v == Fa[u]) continue;

        Fa[v] = u;
        Dep[v] = Dep[u] + 1;
        dfs1(v);

        Siz[u] += Siz[v];
        if (Siz[v] > Siz[Wson[u]]) Wson[u] = v;
    }
}

void dfs2(int u, int chain)
{
    cntv++;
    Id[u] = cntv;
    Dfn[cntv] = u;
    Top[u] = chain;
    End[chain] = max(End[chain], cntv);

    // 第二次树剖时直接更新 F, G 数组（这里直接将 G 放入矩阵更新）
    F[u][0] = 0, F[u][1] = A[u];
    Val[u].mat[0][0] = Val[u].mat[0][1] = 0;
    Val[u].mat[1][0] = A[u];
    if (Wson[u] != 0)
    {
        dfs2(Wson[u], chain);
        // 依照定义，重儿子不应计入 G 数组
        F[u][0] += max(F[Wson[u]][0], F[Wson[u]][1]);
        F[u][1] += F[Wson[u]][0];
    }

    for (int i = Head[u]; i; i = Next[i])
    {
        int v = To[i];
        if (v == Fa[u] || v == Wson[u]) continue;
        dfs2(v, v);

        F[u][0] += max(F[v][0], F[v][1]);
        F[u][1] += F[v][0];
        Val[u].mat[0][0] += max(F[v][0], F[v][1]);
        Val[u].mat[0][1] = Val[u].mat[0][0];
        Val[u].mat[1][0] += F[v][0];
    }
}

void init()
{
    readin();
    dfs1(1);
    dfs2(1, 1);
}

void update_path(int u, int w)
{
    Val[u].mat[1][0] += w - A[u];
    A[u] = w;

    Matrix bef, aft;
    while (u != 0)
    {
        // 计算贡献时，应当用一个 bef 矩阵还原出少掉这个轻儿子的情况，再将 aft 加入更新
        bef = T.Query_Tree(Id[Top[u]], End[Top[u]], 1);
        T.Update_Tree(Id[u], 1);
        aft = T.Query_Tree(Id[Top[u]], End[Top[u]], 1);
        u = Fa[Top[u]];

        Val[u].mat[0][0] += max(aft.mat[0][0], aft.mat[1][0]) - max(bef.mat[0][0], bef.mat[1][0]);
        Val[u].mat[0][1] = Val[u].mat[0][0];
        Val[u].mat[1][0] += aft.mat[0][0] - bef.mat[0][0];
    }
}

void solve()
{
    T.Build_Tree(1, N, 1);

    for (int i = 1; i <= M; ++i)
    {
        int u, w;
        scanf("%d %d", &u, &w);
        update_path(u, w);
        Matrix Ans = T.Query_Tree(Id[1], End[1], 1);
        printf("%d\n", max(Ans.mat[0][0], Ans.mat[1][0]));
    }
}

int main()
{
    init();
    solve();
    return 0;
}
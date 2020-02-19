// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long  left;
    long long  right;
    long long  min;
    long long  max;
    long long  sum;
    long long  delta;
    long long  same;

} tree[400010];
long long  x[100010];
long long  build(long long  id, long long  l, long long  r)
{
    tree[id].left=l;
    tree[id].right=r;
    if(l==r)
    {
        tree[id].sum=x[l];
        tree[id].min=x[l];
        tree[id].max=x[l];
    }
    else
    {
        long long  mid=(tree[id].left+tree[id].right)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min);
    }
}

long long  pushdown(long long  id)
{
    if(tree[id].same)
    {
        tree[id*2].delta=tree[id*2+1].delta=0;
        tree[id*2].same=tree[id*2+1].same=tree[id].same;
        tree[id*2].max=tree[id*2+1].max=tree[id*2+1].min=tree[id*2].min=tree[id].same;
        tree[id*2].sum=(tree[id*2].right-tree[id*2].left+1)*tree[id].same;
        tree[id*2+1].sum=(tree[id*2+1].right-tree[id*2+1].left+1)*tree[id].same;
        tree[id].same=0;
    }
    if(tree[id].delta)
    {
        tree[id*2].delta+=tree[id].delta;
        tree[id*2+1].delta+=tree[id].delta;
        tree[id*2].min+=tree[id].delta;
        tree[id*2+1].min+=tree[id].delta;
        tree[id*2].max+=tree[id].delta;
        tree[id*2+1].max+=tree[id].delta;
        tree[id*2].sum+=(tree[id*2].right-tree[id*2].left+1)*tree[id].delta;
        tree[id*2+1].sum+=(tree[id*2+1].right-tree[id*2+1].left+1)*tree[id].delta;
        tree[id].delta=0;
    }
}
long long  same(long long  id,long long  l,long long  r,long long  set)
{
    if(tree[id].left>=l&&tree[id].right<=r)
    {
        tree[id].delta=0;
        tree[id].max=tree[id].min=tree[id].same=set;
        tree[id].sum=set*(tree[id].right-tree[id].left+1);
        return 0;
    }
    else
    {
        pushdown(id);
        long long  mid=(tree[id].right+tree[id].left)/2;
        if(r<=mid)
            same(id*2,l,r,set);
        else if(l>mid)
            same(id*2+1,l,r,set);
        else
        {
            same(id*2,l,mid,set);
            same(id*2+1,mid+1,r,set);
        }
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min);
    }
}
long long  add(long long  id,long long  l,long long  r,long long  adds)
{
    if(tree[id].left>=l&&tree[id].right<=r)
    {
        tree[id].delta+=adds,tree[id].max+=adds,tree[id].min+=adds;
        tree[id].sum+=adds*(tree[id].right-tree[id].left+1);
        return 0;
    }
    else
    {
        pushdown(id);
        long long  mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid)add(id*2,l,r,adds);
        else
            if(l>mid)add(id*2+1,l,r,adds);
        else
        {
            add(id*2,l,mid,adds);
            add(id*2+1,mid+1,r,adds);
        }
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min);
    }
}
node query(long long  id,long long  l,long long  r)
{
    if(tree[id].left==l&&tree[id].right==r)
    {
        return tree[id];
    }
    else
    {
        node ans;
        pushdown(id);
        long long  mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid) return   query(id*2,l,r);
        else if(l>mid) return query(id*2+1,l,r);
        else
        {
            node r1,r2;
            r1=query(id*2,l,mid);
            r2=query(id*2+1,mid+1,r);
            //printf("r1-sum=%d r2-sum=%d\n",r1.sum,r2.sum);
            ans.sum=r1.sum+r2.sum;
            ans.max=max(r1.max,r2.max);
            ans.min=min(r1.min,r2.min);
            return ans;
        }
    }
}
int  main()
{
    long long  n,m;
    long long  a,b,c;
    scanf("%lld%lld",&n,&m);
    for(long long  i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
    }
    build(1,1,n);
    for(long long  i=0; i<m; i++)
    {
        long long  delta=0;
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a==1)
        {
            scanf("%lld",&delta);
            add(1,b,c,delta);
        }
        // else if(a==1)
        // {
        //     scanf("%d",&delta);
        //     same(1,b,c,delta);
        // }
        else if(a==2)
        {
            node ans;
            ans=query(1,b,c);
            printf("%lld\n",ans.sum);
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long left;
    long long right;
    long long min;
    long long max;
    long long sum;
    long long delta;
    long long mul;

} tree[800010];
long long x[200010];
long long k;
long long build(long long id, long long l, long long r)
{
    tree[id].left=l;
    tree[id].right=r;
    if(l==r)
    {
        tree[id].sum=x[l] ;
        tree[id].min=x[l] ;
        tree[id].max=x[l] ;
        tree[id].mul=1;
    }
    else
    {
        long long mid=(tree[id].left+tree[id].right)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max) ;
        tree[id].sum=tree[id*2].sum +tree[id*2+1].sum ;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min) ;
        tree[id].mul=1;
    }
}

long long pushdown(long long id)
{
    tree[id*2].sum=(tree[id*2].sum*tree[id].mul+tree[id].delta*(tree[id*2].right-tree[id*2].left+1)) ;
    tree[id*2+1].sum=(tree[id*2+1].sum*tree[id].mul+tree[id].delta*(tree[id*2+1].right-tree[id*2+1].left+1)) ;

    tree[id*2].max=(tree[id*2].max*tree[id].mul+tree[id].delta) ;
    tree[id*2+1].max=(tree[id*2+1].max*tree[id].mul+tree[id].delta) ;

    tree[id*2].min=(tree[id*2].min*tree[id].mul+tree[id].delta) ;
    tree[id*2].min=(tree[id*2].min*tree[id].mul+tree[id].delta) ;

    tree[id*2].mul=(tree[id].mul*tree[id*2].mul) ;
    tree[id*2+1].mul=(tree[id].mul*tree[id*2+1].mul) ;

    tree[id*2].delta=(tree[id*2].delta*tree[id].mul+tree[id].delta) ;
    tree[id*2+1].delta=(tree[id*2+1].delta*tree[id].mul+tree[id].delta) ;

    tree[id].mul=1;
    tree[id].delta=0;

}
long long mul(long long id,long long l,long long r,long long muls)
{
    if(tree[id].left>=l&&tree[id].right<=r)
    {
        tree[id].delta=(tree[id].delta*muls),tree[id].max=(tree[id].max*muls),tree[id].min=(tree[id].min*muls),tree[id].sum=(tree[id].sum*muls) ;
        tree[id].mul*=muls;
        return 0;
    }
    else
    {
        pushdown(id);
        long long mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid)
            mul(id*2,l,r,muls);
        else if(l>mid)
            mul(id*2+1,l,r,muls);
        else
        {
            mul(id*2,l,mid,muls);
            mul(id*2+1,mid+1,r,muls);
        }
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max) ;
        tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum) ;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min) ;
    }
}
long long add(long long id,long long l,long long r,long long adds)
{
    if(tree[id].left>=l&&tree[id].right<=r)
    {
        tree[id].delta+=adds,tree[id].max+=adds,tree[id].min+=adds;
        tree[id].sum+=adds*(tree[id].right-tree[id].left+1) ;
        return 0;
    }
    else
    {
        pushdown(id);
        long long mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid)
            add(id*2,l,r,adds);
        else if(l>mid)
            add(id*2+1,l,r,adds);
        else
        {
            add(id*2,l,mid,adds);
            add(id*2+1,mid+1,r,adds);
        }
        tree[id].max=max(tree[id*2].max,tree[id*2+1].max) ;
        tree[id].sum=(tree[id*2].sum+tree[id*2+1].sum) ;
        tree[id].min=min(tree[id*2].min,tree[id*2+1].min) ;
    }
}
node query(long long id,long long l,long long r)
{
    if(tree[id].left==l&&tree[id].right==r)
    {
        return tree[id];
    }
    else
    {
        node ans;
        pushdown(id);
        long long mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid)
            return   query(id*2,l,r);
        else if(l>mid)
            return query(id*2+1,l,r);
        else
        {
            node r1,r2;
            r1=query(id*2,l,mid);
            r2=query(id*2+1,mid+1,r);
            //printf("r1-sum=%d r2-sum=%d\n",r1.sum,r2.sum);
            ans.sum=(r1.sum+r2.sum) ;
            ans.max=max(r1.max,r2.max) ;
            ans.min=min(r1.min,r2.min) ;
            return ans;
        }
    }
}
node ans;
int main()
{
    long long n,m;
    long long a,b,c;
    char op;
    scanf("%lld%lld",&n,&m);
    for(long long i=1; i<=n; i++)
    {
        scanf("%lld",&x[i]);
    }
    build(1,1,n);
    for(long long i=0; i<m; i++)
    {
        long long delta=0;
        cin>>op;
        scanf("%lld%lld",&b,&c);
        if(op=='U')
        {
            //scanf("%lld",&delta);

            ans=query(1,b,b);
            int s= max(0ll,c-ans.max);
            add(1,b,b,s);
        }
        /*else if(a==1)
        {
            scanf("%lld",&delta);
            mul(1,b,c,delta);
        }*/
        else if(op=='Q')
        {
            //node ans;
            ans=query(1,b,c);
            printf("%lld\n",ans.max );
        }
    }
    return 0;
}

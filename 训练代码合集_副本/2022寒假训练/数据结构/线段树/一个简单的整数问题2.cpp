// 一个非常板子的写法

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=100000;
struct node {
    long long l,r;
    long long sum,add;
} setr[N*4+2];
long long mapp[N+2];

void pushup(node &u,node &l,node &r) {
    u.sum=l.sum+r.sum;
}
void pushup(long long u) {
    pushup(setr[u],setr[u<<1],setr[u<<1|1]);
}

void pushdown(node &u,node &l,node &r) {
    if (u.add) {
        l.add+=u.add;
        l.sum+=(long long)(l.r-l.l+1)*u.add;
        r.add+=u.add;
        r.sum+=(long long)(r.r-r.l+1)*u.add;
        u.add=0;
    }
}
void pushdown(long long u) {
    pushdown(setr[u],setr[u<<1],setr[u<<1|1]);
}

void build(long long u,long long l,long long r) {
    if (l==r) {
        setr[u]={l,r,mapp[l]};
    }
    else {
        setr[u]={l,r};
        long long mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long l,long long r,long long d) {
    if (setr[u].l>=l && setr[u].r<=r) {
        setr[u].sum+=(long long)(setr[u].r-setr[u].l+1)*d;
        setr[u].add+=d;
    }
    else {
        pushdown(u);
        long long mid=(setr[u].l+setr[u].r)>>1;
        if (l<=mid) modify(u<<1,l,r,d);
        if (r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}

node query(long long u,long long l,long long r) {
    if (setr[u].r<=r && setr[u].l>=l) return setr[u];
    pushdown(u);
    long long mid=(setr[u].l+setr[u].r)>>1;
    if (l>mid) return query(u<<1|1,l,r);
    else if (r<=mid) return query(u<<1,l,r);
    else {
        node res;
        node left=query(u<<1,l,r);
        node right=query(u<<1|1,l,r);
        pushup(res,left,right);
        return res;
    }
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];
    build(1,1,n);
    char op[2];
    long long l,r;
    long long d;
    while (m--) {
        scanf("%s%d%d",op,&l,&r);
        if (*op=='C') {
            scanf("%lld",&d);
            modify(1,l,r,d);
        }
        else std::cout<<query(1,l,r).sum<<std::endl;
    }
    return 0;
}
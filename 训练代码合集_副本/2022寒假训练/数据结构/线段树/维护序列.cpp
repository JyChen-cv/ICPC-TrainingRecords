#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=100000;
struct node {
    long long l,r;
    long long add,mul,sum;
} setr[N*4+2];
long long mapp[N+2];
long long n,m;
long long mod;

void pushup(node &u,node &l,node &r) {
    u.sum=(l.sum+r.sum)%mod;
}
void pushup(long long u) {
    if (setr[u].l==setr[u].r) return ; 
    pushup(setr[u],setr[u<<1],setr[u<<1|1]);
}

void eva(node &t,long long add,long long mul) {
    // 先 * 后 + 先算优先级高的
    // evaluation
    t.sum=t.sum*mul%mod;
    t.sum=(t.sum+(long long)(t.r-t.l+1)*add)%mod;
    t.mul=t.mul*mul%mod;
    t.add=((t.add*mul%mod)+add)%mod;
}

void pushdown(node &u,node &l,node &r) {
    // 先 * 后 + 先算优先级高的
    // 注意：本层的一定是计算完成的
    eva(l,u.add,u.mul);
    eva(r,u.add,u.mul);
    u.add=0;
    u.mul=1;
}
void pushdown(long long u) {
    if (setr[u].l==setr[u].r) return ;
    pushdown(setr[u],setr[u<<1],setr[u<<1|1]);
}

void build (long long u,long long l,long long r) {
    if (l==r) {
        setr[u]={l,r,0,1,mapp[l]};
    }
    else {
        setr[u]={l,r,0,1};
        long long mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long l,long long r,long long add,long long mul) {
    if (setr[u].l>=l && setr[u].r<=r) {
        eva(setr[u],add,mul);
    }
    else {
        pushdown(u);
        long long mid=(setr[u].l+setr[u].r)>>1;  // 有没有括号都行
        if (l<=mid) modify(u<<1,l,r,add,mul);
        if (r>mid) modify(u<<1|1,l,r,add,mul);
        pushup(u);
    }
}

node query(long long u,long long l,long long r) {
    if (setr[u].l>=l && setr[u].r<=r) return setr[u];
    else {
        pushdown(u);
        long long mid=(setr[u].l+setr[u].r)>>1;
        if (l>mid) return query(u<<1|1,l,r);
        else if (r<=mid) return query(u<<1,l,r);
        else {
            node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
            pushup(res,left,right);
            return res;
        }
    }
}

long long main()
{
    std::cin>>n>>mod;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];
    build(1,1,n);
    std::cin>>m;
    while (m--) {
        long long op,t,g;
        long long c;
        std::cin>>op>>t>>g;
        if (op==2) {
            std::cin>>c;
            modify(1,t,g,c,1);
        }
        else if (op==1) {
            std::cin>>c;
            modify(1,t,g,0,c);
        }
        else {
            std::cout<<query(1,t,g).sum<<std::endl;
        }
    }

    return 0;
}
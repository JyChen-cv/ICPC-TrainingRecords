#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=500000;
struct node {
    long long l,r;
    long long sum,lmax,rmax,tmax;
} setr[N*4+2];
long long n,m;
long long mapp[N+2];

void pushup(node &u,node &l,node &r){
    u.sum=l.sum+r.sum;
    u.lmax=std::max(l.lmax,l.sum+r.lmax);
    u.rmax=std::max(l.rmax+r.sum,r.rmax);
    u.tmax=std::max(std::max(l.tmax,r.tmax),l.rmax+r.lmax);
    // u.tmax=std::max(std::max(u.lmax,u.rmax),std::max(std::max(l.tmax,r.tmax),l.rmax+r.lmax));
    // 这里不用这样写，因为显然有sum<=lmax,rmax<=tmax,因为tmax没有限制，lmax,rmax各限制了一边，sum限制了两边，所以上面的式子显得非常多余
    // u.lmax,u.rmax的值一定小于l.rmax+r.lmax，所以被包含了
}
void pushup(long long u) {  // 这样写虽然函数定义的比较复杂，但是调用变得非常简单
    pushup(setr[u],setr[u<<1],setr[u<<1|1]);
}

void build(long long u,long long l,long long r) {
    if (l==r) {
        setr[u]={l,r,mapp[r],mapp[r],mapp[r],mapp[r]};  // 不是0,题目规定了最少包含一个数字
    }
    else {
        setr[u]={l,r};
        long long mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long x,long long v) {
    if (setr[u].l==x && setr[u].r==x) {
        setr[u]={x,x,v,v,v,v};
        mapp[x]=v;
    }
    else {
        long long mid=(setr[u].l+setr[u].r)>>1;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

node query(long long u,long long l,long long r) {
    if (setr[u].l>=l && setr[u].r<=r) return setr[u];
    else {
        long long mid=(setr[u].l+setr[u].r)>>1;  // 这里开始这个函数的写法变的非常特殊
        if (l>mid) return query(u<<1|1,l,r);
        else if (r<=mid) return query(u<<1,l,r);
        else {
            node left=query(u<<1,l,r);
            node right=query(u<<1|1,l,r);
            node res;
            pushup(res,left,right);
            return res;
        }
    }
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];
    build(1,1,n);

    long long k,x,y;
    while (m--) {
        std::cin>>k>>x>>y;
        if (k==1) {
            if (x>y) std::swap(x,y);
            std::cout<<query(1,x,y).tmax<<std::endl;
        }
        else modify(1,x,y);
    }
    return 0;
}
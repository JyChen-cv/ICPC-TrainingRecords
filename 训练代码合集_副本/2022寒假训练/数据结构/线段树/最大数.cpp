#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=200000;
struct node {
    long long l,r;
    long long v;
} setr[N*4+2];

void pushup(long long u) {
    setr[u].v=std::max(setr[u<<1].v,setr[u<<1|1].v);
}

void build(long long u,long long l,long long r) {
    setr[u]={l,r};
    if (l==r) return ;
    long long mid=(l+r)/2;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

long long query(long long u,long long l,long long r) {
    if (l<=setr[u].l && r>=setr[u].r) return setr[u].v;
    long long mid=(setr[u].l+setr[u].r)/2;
    long long v=0;
    if (l<=mid) v=query(u<<1,l,r);
    if (r>mid) v=std::max(v,query(u<<1|1,l,r));
    return v;
}

void modify(long long u,long long x,long long v) {
    if (setr[u].l==x && setr[u].r==x) {
        setr[u].v=v;
    }
    else {
        long long mid=(setr[u].l+setr[u].r)/2;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

long long main()
{
    long long n=0,last=0;
    long long m,p;
    std::cin>>m>>p;
    build(1,1,m);
    
    long long x;
    char op[2];
    while (m--) {
        scanf("%s%d",op,&x);
        if (*op=='Q') {
            last=query(1,n-x+1,n);
            std::cout<<last<<std::endl;
        }
        else {
            modify(1,n+1,((long long)last+x)%p);
            n++;
        }
    }
    return 0;
}

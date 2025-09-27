#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=500000;
struct node {
    long long l,r;
    long long sum,d;
} setr[N*4+2];
long long mapp[N+2];

long long gcd(long long x,long long y) {
    return y ? gcd(y,x%y) : x;
}

void pushup(node &u,node &l,node &r) {  // 这样写pushup好处多多
    u.sum=l.sum+r.sum;
    u.d=gcd(l.d,r.d);
}
void pushup(long long u) {
    pushup(setr[u],setr[u<<1],setr[u<<1|1]);
}

void build(long long u,long long l,long long r) {
    if (l==r) {
        long long ls=mapp[r]-mapp[r-1];
        setr[u]={l,r,ls,ls};
    }
    else {
        setr[u]={l,r};  //  别忘记下标
        long long mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long x,long long v) {
    if (setr[u].l==x && setr[u].r==x) {
        setr[u].sum+=v;
        setr[u].d=setr[u].sum;
    }
    else {
        long long mid=(setr[u].l+setr[u].r)>>1;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

node query(long long u,long long l,long long r) {
    if (l>r) return {0};
    if (setr[u].l>=l && setr[u].r<=r) return setr[u];
    else {  // 记住这种写法，传结构体非常的省事，且美观，其他方法维护一个变量还好，维护多个变量时代码过于冗长
        long long mid=(setr[u].l+setr[u].r)>>1;
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
    long long l,r;
    // std::cin>>l>>r;
    long long d;
    char op[2];
    while (m--) {
        scanf("%s%d%d",op,&l,&r);
        if (*op=='Q') {
            node a1=query(1,1,l),a2=query(1,l+1,r);  // 这一步是纯粹的数学公式推导看视频的1:30:00左右的讲解
            std::cout<<std::abs(gcd(a1.sum,a2.d))<<std::endl;  // abs前面必须有std
        }
        else {
            std::cin>>d;
            modify(1,l,d);
            if (r+1<=n) modify(1,r+1,-d);  // 判不判定都可以吧
        }
    } 

    return 0;
}
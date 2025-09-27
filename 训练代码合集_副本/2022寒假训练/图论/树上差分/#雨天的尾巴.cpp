#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const long long N=1000001,M=1000000;
long long ver[N*2+2],head[N+2],nxt[N*2+2],f[N+2][30],dep[N+2];
long long tot,root[N+2],total,t,n,m,sz;
struct group { // 用来把操作离线
    long long x,y,z;
} op[M+2];
struct node {
    long long l_s,r_s; // 左右儿子
    long long dat,num; // 最大值 物品类型
} setr[N*4];

void add(long long x,long long y) {
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

long long build() {
    total++;
    setr[total]=(node){0,0,0,0}; // 定义了多个结构体，所以需要标出类型
    return total;
}

void pushup(node &u,node &l,node &r) {
    if (l.dat>=r.dat) {
        u.dat=l.dat;
        u.num=l.num;
    }
    else {
        u.dat=r.dat;
        u.num=r.num;
    }
}
void pushup(long long u) {
    // 用左右儿子向上计算
    pushup(setr[u],setr[setr[u].l_s],setr[setr[u].r_s]);
}

void modify(long long u,long long l,long long r,long long val,long long delta) {
    if (l==r) { // 若找到一个点，就更改
        setr[u].dat+=delta;
        setr[u].num=val; // 该点的最大值一定来自自己
        return ;
    }
    long long mid=(l+r)>>1;
    if (val<=mid) {
        if (!setr[u].l_s) setr[u].l_s=build(); // 动态开点
        modify(setr[u].l_s,l,mid,val,delta);
    }
    else {
        if (!setr[u].r_s) setr[u].r_s=build();
        modify(setr[u].r_s,mid+1,r,val,delta);
    }
    pushup(u);
}

void dfs(long long x) {
    for (long long i=1;i<=t;i++) {
        f[x][i]=f[f[x][i-1]][i-1];
    }
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (dep[y]) continue;
        dep[y]=dep[x]+1;
        f[y][0]=x;
        dfs(y);
    }
}

long long lca(long long x,long long y) {
    if (dep[y]>dep[x]) std::swap(x,y);
    for (long long i=t;i>=0;i--) {
        if (dep[f[x][i]]>=dep[y]) x=f[x][i];
    }
    if (x==y) return x;
    for (long long i=t;i>=0;i--) {
        if (f[x][i]!=f[y][i]) {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}

long long merge(long long p,long long q,long long l,long long r) {
    if (!p) return q;
    if (!q) return p;
    if (l==r) {
        setr[p].dat+=setr[q].dat;
        return p;
    }
    long long mid=(l+r)>>1;
    setr[p].l_s=merge(setr[p].l_s,setr[q].l_s,l,mid);
    setr[p].r_s=merge(setr[p].r_s,setr[q].r_s,mid+1,r);
    pushup(p);
    return p;
}

void deal(long long x) {
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (dep[y]<dep[x]) continue;
        deal(y);
        merge(root[x],root[y],1,sz); // 把y树加到x树上去
    }
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<n;i++) {
        long long a,b;
        std::cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    t=(long long)(log(n)/log(2))+1;
    dep[1]=1;
    dfs(1);
    
    std::vector<long long> q; // 用于离散化的数组
    for (long long i=1;i<=m;i++) {
        std::cin>>op[i].x>>op[i].y>>op[i].z;
        q.push_back(op[i].z);
    }
    std::sort(q.begin(),q.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    sz=(long long)q.size();
    for (long long i=1;i<=m;i++) op[i].z=(long long)(std::lower_bound(q.begin(),q.end(),op[i].z)-q.begin())+1;
    
    // 动态开点
    for (long long i=1;i<=n;i++) root[i]=build(); // root[i]=i
    for (long long i=1;i<=m;i++) {
        long long ff=lca(op[i].x,op[i].y);
        // 这里是四个操作，想清楚!
        modify(root[op[i].x],1,sz,op[i].z,1);
        modify(root[op[i].y],1,sz,op[i].z,1);
        modify(root[ff],1,sz,op[i].z,-1);
        if (f[ff][0]>0) modify(root[f[ff][0]],1,sz,op[i].z,-1);
    }
    // 线段树合并
    deal(1);
    for (long long i=1;i<=n;i++) {
        if (setr[i].dat) std::cout<<q[setr[i].num-1]<<std::endl;
        else std::cout<<0<<std::endl;
    }
    
    return 0;
}
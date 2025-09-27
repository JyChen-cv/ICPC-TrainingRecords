// 扫描线
// lazy tag，线段树的操作永远往下看
// 利用扫描线自身的性质来优化，避免写懒标记
// 每次查找直接返回根节点的信息，query的时候不需要pushdown
// 所有的操作都是成对出现，所以modify也不需要pushdown

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const long long N=200000;
struct segement {
    double x,y1,y2;
    long long k;
    bool operator < (const segement &t)const {
        return x<t.x;
    }
} seg[N+2];
struct node {
    long long l,r;
    long long cnt;
    double len;
} setr[N*4+2];
std::vector<double> ys;

long long find(double x) {
    return lower_bound(ys.begin(),ys.end(),x)-ys.begin();
}

void pushup(node &u,node &l,node &r) {
    if (u.cnt) {
        u.len=(ys[u.r+1]-ys[u.l]);
    }
    else if (u.l!=u.r) {  // 排除叶子结点
        u.len=l.len+r.len;
    }
    else u.len=0;
}
void pushup(long long u) {
    pushup(setr[u],setr[u<<1],setr[u<<1|1]);
}

void build(long long u,long long l,long long r) {
    setr[u]={l,r,0,0};
    if (l!=r) {
        long long mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(long long u,long long l,long long r,long long k) {
    if (setr[u].l>=l && setr[u].r<=r) {
        setr[u].cnt+=k;
        pushup(u);
    }
    else {
        long long mid=(setr[u].l+setr[u].r)>>1;
        if (l<=mid) modify(u<<1,l,r,k);
        if (r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

long long main()
{
    long long n,T=0;
    while (scanf("%d",&n),n) {  // 这里写法有点怪，但是好省事
        ys.clear();
        
        for (long long i=0,j=0;i<n;i++) {
            double x1,x2,y1,y2;
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[j++]={x1,y1,y2,1};
            seg[j++]={x2,y1,y2,-1};
            ys.push_back(y1);
            ys.push_back(y2);
        }

        build(1,0,ys.size()-2);  // 区间的个数比点的个数还要捎一个

        // 离散化 // 去重？
        std::sort(ys.begin(),ys.end());
        ys.erase(unique(ys.begin(),ys.end()),ys.end());  // unique返回的是一个迭代器，指向第一个重复元素，erase就是把重复元素都删除掉
        std::sort(seg,seg+n*2);

        double res=0;
        for (long long i=0;i<n*2;i++) {
            if (i>0) res+=setr[1].len*(seg[i].x-seg[i-1].x);
            modify(1,find(seg[i].y1),find(seg[i].y2)-1,seg[i].k);
        }

        prlong longf("Test case #%d\n",++T);
        prlong longf("Total explored area: %.2lf\n\n",res);
    }   
    return 0;
}
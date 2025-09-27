#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

const long long N=50000;
long long fa[N+2],d[N+2];
struct group {
    long long a,b;
    std::string c;
} mapp[N+2];
// 这道题目的难点在于它是强制在线的算法
// 但这道题目经过前缀和的转换后只有两个集合，所以倒也简单了
// 采用边带权并查集和扩展域并查集都能得到结果，这里使用边带权并查集
// 相同关系表示0，不同关系表示1
// d数组储存当前元素与它父亲的关系

long long find(long long x)
{
    if (fa[x]==x) return x;
    long long ls=find(fa[x]);
    d[x]^=d[fa[x]];
    return fa[x]=ls;
}

long long deal(std::string l)
{
    if (l=="odd") return 1;
    else return 0;
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    n=std::min(n,m*2);
    for (long long i=1;i<=n;i++) fa[i]=i;
    std::vector<long long> deq; // deq问就是瞎起的
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].a>>mapp[i].b>>mapp[i].c;
        mapp[i].a--;
        deq.push_back(mapp[i].a);
        deq.push_back(mapp[i].b);
    }
    std::sort(deq.begin(),deq.end());
    deq.erase(unique(deq.begin(),deq.end()),deq.end());
    for (long long i=1;i<=m;i++) {
        mapp[i].a=lower_bound(deq.begin(),deq.end(),mapp[i].a)-deq.begin()+1;
        mapp[i].b=lower_bound(deq.begin(),deq.end(),mapp[i].b)-deq.begin()+1;
        long long a=find(mapp[i].a);
        long long b=find(mapp[i].b);
        if (a==b) {
            if ((d[mapp[i].a]^d[mapp[i].b])!=deal(mapp[i].c)) {
                std::cout<<(i-1)<<std::endl;
                return 0;
            }
        }
        else {
            fa[a]=b;
            d[a]=d[mapp[i].a]^d[mapp[i].b]^deal(mapp[i].c);
        }
    }
    std::cout<<m<<std::endl;
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

const long long N=1000;
long long n,m,fa[N*N];

long long deal(long long x,long long y)
{
    return (x-1)*n+y;
}

long long find(long long x) 
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    std::cin>>m>>n;
    for (long long i=1;i<=n*m;i++) fa[i]=i;
    long long x1,x2,y1,y2;
    while (std::cin>>x1>>y1>>x2>>y2) {
        fa[find(deal(x1,y1))]=find(deal(x2,y2));
    }

    long long ans=0;
    for (long long i=2;i<=m;i++) {  // 先把列上需要连的先连上
        for (long long j=1;j<=n;j++) {
            long long a=find(deal(i,j)),b=find(deal(i-1,j));
            if (a!=b) {
                fa[a]=b;
                ans++;
            }
        }
    }
    for (long long i=1;i<=m;i++) {  // 再把行上需要连的连上
        for (long long j=2;j<=n;j++) {
            long long a=find(deal(i,j)),b=find(deal(i,j-1));
            if (a!=b) {
                fa[a]=b;
                ans+=2;
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}

// 还以为要跑一个prim，搞一个从某一点出发的类似于队列的遍历，后来发现自己想复杂了，暴力两遍kruskal即可
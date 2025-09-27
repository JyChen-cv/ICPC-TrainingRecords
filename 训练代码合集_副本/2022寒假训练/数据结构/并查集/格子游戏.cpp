#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=40000;
long long fa[N+2],n,m;

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long deal(long long x,long long y)
{
    return n*(x-1)+y;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n*n;i++) fa[i]=i;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        char c;
        std::cin>>a>>b>>c;
        long long aa,bb;
        if (c=='D') {
            aa=deal(a,b);
            bb=deal(a+1,b);
            aa=find(aa);
            bb=find(bb);
        }
        else {
            aa=deal(a,b);
            bb=deal(a,b+1);
            aa=find(aa);
            bb=find(bb);
        }
        if (aa==bb) {
            std::cout<<i<<std::endl;
            return 0;
        }
        else {
            fa[aa]=bb;
        }
    }
    std::cout<<"draw"<<std::endl;
    return 0;
}
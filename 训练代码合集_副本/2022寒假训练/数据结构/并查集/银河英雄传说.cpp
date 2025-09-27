#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=30000;
long long fa[N+2],s[N*2],d[N+2];

// fa[i]指向谁，s[i]就代表谁后面的第i个
// 带权并查集一定是相对的，不是绝对的

long long find(long long x)
{
    if (fa[x]==x) return x;
    long long root=find(fa[x]);
    d[x]+=d[fa[x]];
    return fa[x]=root;
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=N;i++) {
        fa[i]=i;
        s[i]=1;
    }
    for (long long i=1;i<=n;i++) {
        char c;
        long long a,b;
        std::cin>>c>>a>>b;
        long long aa=find(a);
        long long bb=find(b);
        if (c=='C') {
            if (aa!=bb) {
                std::cout<<-1<<std::endl;    
            }
            else std::cout<<std::max(0,(std::abs(d[a]-d[b])-1))<<std::endl;
        }
        else {
            if (aa==bb) continue;
            fa[aa]=bb;
            d[aa]=s[bb];
            s[bb]+=s[aa];
        }
        // std::cout<<c<<" "<<d[a]<<" "<<d[b]<<std::endl;
    }

    return 0;
}
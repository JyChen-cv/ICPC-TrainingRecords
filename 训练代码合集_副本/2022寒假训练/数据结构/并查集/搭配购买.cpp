#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=10000;
long long mapp[N+2],w[N+2],fa[N+2],v[N+2],sum[N+2],f[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m,k;
    std::cin>>n>>m>>k;
    for (long long i=1;i<=n;i++) {
        fa[i]=i;
        std::cin>>mapp[i]>>w[i];
    }
    for (long long i=1;i<=m;i++) {
        long long a,b;
        std::cin>>a>>b;
        fa[find(b)]=find(a);
    }

    for (long long i=1;i<=n;i++) {
        // std::cout<<find(i)<<std::endl;
        sum[find(i)]+=w[i];
        v[find(i)]+=mapp[i];
    }
    for (long long i=1;i<=n;i++) {
        if (!v[i]) continue;
        // std::cout<<i<<std::endl;
        for (long long j=k;j>=v[i];j--) {
            f[j]=std::max(f[j],f[j-v[i]]+sum[i]);
        }
    }
    std::cout<<f[k]<<std::endl;

    return 0;
}
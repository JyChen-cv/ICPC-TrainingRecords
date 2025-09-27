#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=200000;
long long fa[N+2],s[N+2];

long long find(long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m,k;
    std::cin>>n>>m>>k;
    for (long long i=1;i<=n;i++) fa[i]=i;
    for (long long i=1;i<=n;i++) s[i]=1;
    for (long long i=1;i<=m;i++) {
        long long a,b;
        std::cin>>a>>b;
        if (i>k) {
            if (find(a)==find(b)) continue;
            s[find(b)]+=s[find(a)];
            fa[find(a)]=find(b);
        }
    }
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        // std::cout<<s[find(i)]<<" ";
        ans+=((long long)n-s[find(i)]);
    }
    std::cout<<(ans/2)<<std::endl;
    return 0;
}
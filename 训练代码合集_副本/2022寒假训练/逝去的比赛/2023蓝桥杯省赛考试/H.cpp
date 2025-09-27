#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=5000;
long long mapp[N+2],f[N+2];
long long n;

long long lowbit(long long x) {
    return x&(-x);
}

void add(long long x,long long y)
{
    while (x<=n) {
        f[x]^=y;
        x+=lowbit(x);
    }
}

long long ask(long long x)
{
    long long ls=0;
    while (x) {
        ls^=f[x];
        x-=lowbit(x);
    }
    return ls;
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        add(i,mapp[i]);
    }
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        for (long long j=i;j<=n;j++) {
            ans+=(ask(i-1)^ask(j));
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
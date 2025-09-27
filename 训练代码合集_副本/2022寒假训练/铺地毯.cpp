#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

const long long N=10000;
struct group {
    long long a;
    long long b;
    long long c;
    long long d;
} mapp[N+2];

bool check(long long x,long long y,long long z)
{
    if (x>=mapp[z].a && x<=mapp[z].c) 
        if (y>=mapp[z].b && y<=mapp[z].d) return 1;
    return 0;
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i].a>>mapp[i].b>>mapp[i].c>>mapp[i].d;
        mapp[i].c+=mapp[i].a-1;
        mapp[i].d+=mapp[i].b-1;
    }
    long long xx,yy;
    std::cin>>xx>>yy;
    for (long long i=n;i>=1;i--) {
        if (check(xx,yy,i)) {
            std::cout<<i<<std::endl;
            break;
        }
    }

    return 0;
}
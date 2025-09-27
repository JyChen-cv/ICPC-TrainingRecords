#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

bool mapp[1005];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        for (long long j=1;j<=n;j++) {
            if (j%i==0) mapp[j]^=1;
        }
    }

    for (long long i=1;i<=n;i++) {
        if (mapp[i]) std::cout<<i<<" ";
    }
    return 0;
}
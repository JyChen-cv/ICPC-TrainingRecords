#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=500000;
long long mapp[N+2],range[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (range,0,sizeof(range));

        long long n,m;
        std::cin>>n>>m;
        for (long long i=1;i<=m;i++) {
            std::cin>>mapp[i];
            range[mapp[i]++]
        }
    }

    return 0;
}
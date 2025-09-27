#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=200;
long long mapp[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset(mapp,0,sizeof(mapp));

        long long n;
        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
            std::cout<<(n+1-mapp[i])<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
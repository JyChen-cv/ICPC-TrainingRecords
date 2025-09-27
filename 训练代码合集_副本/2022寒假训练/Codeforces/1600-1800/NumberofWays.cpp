#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=500000;
long long mapp[N+2];

long long main()
{
    long long n;
    std::cin>>n;
    long long sum=0;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        sum+=mapp[i];
    }
    for (long long i=1;i<=n;i++) {
        
    }
    return 0;
}
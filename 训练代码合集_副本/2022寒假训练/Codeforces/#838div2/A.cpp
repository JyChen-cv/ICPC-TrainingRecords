#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

long long deal(long long x)
{
    long long tag=0,cnt=0;;
    if (x%2==1) tag=1;
    while (x) {
        cnt++;
        x/=2;
        if (tag^(x%2)) return cnt;
    }
    return 1000000;
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        long long minn=1000000,sum=0;
        for (long long i=1;i<=n;i++) {
            long long a;
            std::cin>>a;
            sum+=a;
            minn=std::min(minn,deal(a));
        }
        if (sum%2==0) std::cout<<0<<std::endl;
        else std::cout<<minn<<std::endl;
    }
    return 0;
}
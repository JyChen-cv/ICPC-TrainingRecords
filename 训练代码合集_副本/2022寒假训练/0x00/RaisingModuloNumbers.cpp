#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

// long long qm(long long a,long long b,long long c)
// {
//     if (b==0) return 1;
//     if (b%2==1) return qm(a,(b-1)/2,c)*a%c*qm(a,(b-1)/2,c)%c;
//     else return qm(a,b/2,c)*qm(a,b/2,c)%c;
// }     //这样相当于硬算

long long qm(long long a,long long b,long long c)
{
    if (b==0) return 1;
    if (b%2==1) {
        long long x=qm(a,(b-1)/2,c);
        return x*x%c*a%c;
    }
    else {
        long long x=qm(a,b/2,c);
        return x*x%c;
    }
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long mod,ans=0;
        std::cin>>mod;
        long long nn;
        std::cin>>nn;
        for (long long j=1;j<=nn;j++) {
            long long aa,bb;
            std::cin>>aa>>bb;
            ans+=qm(aa,bb,mod);
            ans%=mod;
        }
        std::cout<<ans<<std::endl;
    }

    return 0;
}
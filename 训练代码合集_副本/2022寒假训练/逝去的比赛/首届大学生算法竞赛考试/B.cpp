#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

const long long N=500000;
long long mapp[N+2];
long long n;

bool check (long long x)
{
    long long cnt=1;
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        if (ans+mapp[i]<=x) ans+=mapp[i];
        else {
            ans=mapp[i];
            cnt++;
            if (cnt>4) return 0;
        }
    }
    return 1;
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    long long l=0,r=1e15;
    while (l<r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    long long cnt=1e15,ls=0,ans=0;
    for (long long i=1;i<=n;i++) {
        if (ls+mapp[i]<=l) {
            ls+=mapp[i];
        }
        else {
            cnt=std::min(cnt,ls);
            ans=std::max(ans,ls);
            ls=mapp[i];
        }
    }
    std::cout<<(ans-cnt)<<std::endl;
    return 0;
}
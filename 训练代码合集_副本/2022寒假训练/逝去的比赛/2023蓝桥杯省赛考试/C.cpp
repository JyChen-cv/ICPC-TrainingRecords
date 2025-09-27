#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

bool deal(long long x)
{
    if (x%2==1) return 1;
    else if (x%4==0) return 1;
    else return 0;
}

long long main()
{
    long long l,r;
    std::cin>>l>>r;
    if ((l<=5000 && r<=5000) || (r-l)<=1000000) {
        long long ans=0;
        for (long long i=l;i<=r;i++) {
            if (deal(i)) ans++;
        }
        std::cout<<ans<<std::endl;
        return 0;
    }
    
    long long ls=r-l+1;
    long long anss;
    if (l%2==0) {
        anss=ls/2;
    }
    else {
        anss=(ls+1)/2;
    }

    if (l%2==1) l++;
    if (r%2==1) r--;
    l/=2;
    r/=2;
    ls=(r-l)+1;
    if (l%2==0) {
        anss+=(ls+1)/2;
    }
    else anss+=(ls)/2;
    std::cout<<anss<<std::endl;
    
    return 0;
}
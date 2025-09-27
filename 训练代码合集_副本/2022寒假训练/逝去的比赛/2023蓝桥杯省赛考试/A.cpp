#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

bool deal(long long x)
{
    std::vector<long long> s;
    while (x) {
        long long ls=x%10;
        x/=10;
        s.push_back(ls);
    }
    if ((long long)s.size()%2==1) return 0;
    long long ls1=0,ls2=0;
    for (long long i=0;i<(long long)s.size();i++) {
        if (i<((long long)s.size()/2)) ls1+=s[i];
        ls2+=s[i];
    }
    if (ls2==ls1*2) return 1;
    else return 0;
}

long long main()
{
    long long ans=0;
    for (long long i=1;i<=100000000;i++) {
        if (deal(i)) {
            ans++;
            // std::cout<<i<<" ";
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
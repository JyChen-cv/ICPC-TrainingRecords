#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n;
        std::cin>>n;
        std::vector<long long> v;
        v.push_back(0);
        for (long long i=1;i<=n;i++) {
            long long a;
            std::cin>>a;
            v.push_back(0);
            if (a==0) continue;
            else if (a>=(long long)v.size()) {
                v[0]++;
                v[(long long)v.size()-1]--;
            }
            else {
                v[(long long)v.size()-a-1]++;
                v[(long long)v.size()-1]--;
            }
        }
        if (v[0]) std::cout<<1<<" ";
        else std::cout<<0<<" ";
        for (long long i=1;i<(long long)v.size()-1;i++) {
            v[i]+=v[i-1];
            if (v[i]) std::cout<<1<<" ";
            else std::cout<<0<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
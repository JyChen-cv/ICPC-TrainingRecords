#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <vector>
const long long N=200000;
std::pair<long long,long long> mapp[N+2];
std::vector<long long> f;

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i].first>>mapp[i].second;
    }
    std::sort(mapp+1,mapp+n+1);
    for (long long i=1;i<=n;i++) {
        if (f.size()==0 || f[(long long)f.size()-1]<mapp[i].second) f.push_back(mapp[i].second);
        else {
            long long l=std::lower_bound(f.begin(),f.end(),mapp[i].second)-f.begin();
            f[l]=mapp[i].second;
        }
    }
    
    std::cout<<f.size()<<std::endl;
    return 0;
}
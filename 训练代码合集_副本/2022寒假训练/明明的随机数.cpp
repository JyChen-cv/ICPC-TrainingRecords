#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=100;
long long mapp[N+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }
    std::sort(mapp+1,mapp+n+1);
    long long tag=mapp[0];
    std::vector<long long> ans;
    for (long long i=1;i<=n;i++) {
        if (mapp[i]==tag) continue;
        tag=mapp[i];
        ans.push_back(mapp[i]);
    }

    std::cout<<ans.size()<<std::endl;
    for (long long i=0;i<ans.size();i++) std::cout<<ans[i]<<" ";

    return 0;
}
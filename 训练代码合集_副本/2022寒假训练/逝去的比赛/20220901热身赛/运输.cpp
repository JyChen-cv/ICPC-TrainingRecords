#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

std::priority_queue<long long,std::vector<long long> > mapp;

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        long long x;
        std::cin>>x;
        mapp.push(x);
    }
    for ( ; ; ) {
        long long ls=mapp.top();
        mapp.pop();
        long long lss=mapp.top();
        mapp.pop();
        mapp.push((ls+lss)/m);
        if (mapp.size()==1) break;
    }
    long long ans=mapp.top();
    std::cout<<ans<<std::endl;

    return 0;
}
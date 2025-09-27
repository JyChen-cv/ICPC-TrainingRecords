#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=2e5;
long long mapp[N+2],n;
long long zhi[N+2];
long long ans;
std::vector<long long> e;

long long lowbit(long long x) 
{
    return x&(-x);
}

long long ask(long long x) {
    long long ls=0;
    while (x) {
        ls+=zhi[x];
        x-=lowbit(x);
    }
    return ls;
}

void add(long long x,long long y)
{
    while (x<=n) {
        zhi[x]+=y;
        x+=lowbit(x);
    }
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        e.push_back(mapp[i]);
    }
    std::sort(e.begin(),e.end());
    e.erase(unique(e.begin(),e.end()),e.end());
    for (long long i=1;i<=n;i++) {
        mapp[i]=lower_bound(e.begin(),e.end(),mapp[i])-e.begin();
        mapp[i]++;
    }
    for (long long i=n;i>=1;i--) {
        ans=ans+ask(mapp[i]-1);
        add(mapp[i],1);
    }
    std::cout<<ans<<std::endl;

    return 0;
}
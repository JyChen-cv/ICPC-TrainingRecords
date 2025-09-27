#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

std::string mapp;
std::vector<long long> s;
long long cnt[12];

long long lowbit(long long x)
{
    return x&(-x);
}

void add(long long x,long long y)
{
    while (x<=10) {
        cnt[x]+=y;
        x+=lowbit(x);
    }
}

long long ask(long long x)
{
    long long ls=0;
    while (x) {
        ls+=cnt[x];
        x-=lowbit(x);
    }
    return ls;
}

long long main()
{
    std::cin>>mapp;
    for (long long i=0;i<(long long)mapp.size();i++) {
        s.push_back(mapp[i]-'0'+1);
    }

    long long ans=0;
    for (long long i=(long long)s.size()-1;i>=0;i--) {
        ans+=ask(s[i]-1);
        // ans+=deal(ask(s[i]));
        add(s[i],1);
    }
    std::cout<<ans<<std::endl;
    return 0;
}
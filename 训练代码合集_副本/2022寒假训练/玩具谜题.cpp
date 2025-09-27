#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

const long long N=100000;
long long mapp[N+2];
long long n,m;
std::string car[N+2];

void deal(long long &x,long long y,long long z)
{
    if (y==1) {
        x+=z;
        x%=n;
    }
    else {
        x-=z;
        while (x<=0) x+=n;
    } 
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i]>>car[i];
    }

    // 00 和 01 是左  01 和 10 是右
    long long tag=1;
    while (m--) {
        long long dir,num;
        std::cin>>dir>>num;
        long long direction=dir^mapp[tag];
        deal(tag,direction,num);
    }

    if (tag==0) tag=n;
    std::cout<<car[tag]<<std::endl;

    return 0;
}
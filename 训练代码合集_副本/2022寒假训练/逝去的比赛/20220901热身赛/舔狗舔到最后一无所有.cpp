#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long MaxN=100000,mod=1e9+7;
long long mapp[MaxN+5][3];
long long xxx;

long long deal(long long x,long long y)
{
    if (x==xxx) return y;
    if (mapp[x][y]) return mapp[x][y];
    if (y==0) return 0;
    else if (y==1) {
        return mapp[x][1]=1*(deal(x+1,0)+deal(x+1,2))%mod;
    }
    else {
        return mapp[x][2]=2*((deal(x+1,1)+deal(x+1,2))%mod)%mod;
    }
}

long long main()
{
    long long t;
    std::cin>>t;

    while (t--) {
        memset(mapp,0,sizeof(mapp));

        std::cin>>xxx;        
        deal(2,1);
        deal(2,2);

        if (xxx==1) std::cout<<3<<std::endl;
        else std::cout<<(mapp[2][1]+mapp[2][2])%mod*3%mod<<std::endl;
    }

    return 0;
}
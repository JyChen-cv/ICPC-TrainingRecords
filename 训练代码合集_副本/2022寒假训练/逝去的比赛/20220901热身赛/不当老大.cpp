#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
 
const long long MaxN=10000000;
long long mapp[MaxN+5];
 
inline bool read(long long & x) 
{
    char c=getchar();
    if (c==EOF) return 0;
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return 1;
}
 
long long main()
{
    // freopen("okok.in","r",stdin);
 
    long long t;
    std::cin>>t;
    while (t--) {
        // std::cout<<t<<std::endl;
        long long xx;
        std::cin>>xx;
        memset (mapp,0,sizeof(mapp));
 
        for (long long i=1;i<=xx;i++) {
            std::cin>>mapp[i];
        }
        std::sort(mapp+1,mapp+xx+1);
        std::cout<<std::abs(mapp[xx-1]-mapp[2])<<std::endl;
    }
 
    return 0;
}
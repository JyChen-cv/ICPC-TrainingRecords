#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=500;
long long mapp[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (mapp,0,sizeof(mapp));

        long long n;
        std::cin>>n;
        long long sum1=0,sum2=0;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
            sum1+=mapp[i];
        } 
        long long tag=0;
        for (long long i=1;i<=n;i++) {
            long long a;
            std::cin>>a;
            if (a!=mapp[i]) {
                tag++;
            }
            sum2+=a;
        }
        long long ls=(std::abs(sum1-sum2)+1);
        std::cout<<std::min(ls,tag)<<std::endl;
    }

    return 0;
}
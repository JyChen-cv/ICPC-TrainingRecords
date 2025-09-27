#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

long long mapp[25];

long long main()
{
    long long x;
    while (std::cin>>x) {
        mapp[x]++;
        for (long long i=2;i<=20;i++) {
            std::cin>>x;
            mapp[x]++;
        }
        long long ans=0,maxx=-1;
        for (long long i=1;i<=10;i++) {
            if (mapp[i]>maxx) {
                ans=i;
                maxx=mapp[i];
            }
        }
        std::cout<<ans<<std::endl;

        memset(mapp,0,sizeof(mapp));
    }

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=100000;
char mapp[N+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        if (mapp[i]=='x') {
            long long cnt=1;
            for (long long j=i+1;j<=n;j++) {
                if (mapp[j]=='x') {
                    cnt++;
                    i=j;
                }
                else {
                    break;
                }
            }
            if (cnt>=3) {
                ans+=cnt-2;
            }
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}
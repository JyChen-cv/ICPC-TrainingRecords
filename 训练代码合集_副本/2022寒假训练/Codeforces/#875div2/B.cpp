#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=200000;
long long mapp[N+2],mapp1[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {

        long long n,ls=1,a,b=0;
        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            std::cin>>a;
            if (a==b) {
                ls++;
            }
            else {
                mapp[b]=std::max(mapp[b],ls);
                ls=1;
            }
            // std::cout<<b<<" "<<ls<<std::endl;
            b=a;
        }
        mapp[b]=std::max(mapp[b],ls);
        ls=1,a,b=0;
        for (long long i=1;i<=n;i++) {
            std::cin>>a;
            if (a==b) {
                ls++;
            }
            else {
                mapp1[b]=std::max(mapp1[b],ls);
                ls=1;
            }
            b=a;
        }
        mapp1[b]=std::max(mapp1[b],ls);
        long long ans=0;
        for (long long i=1;i<=2*n;i++) {
            ans=std::max(ans,mapp[i]+mapp1[i]);
            mapp[i]=0;
            mapp1[i]=0;
        }
        
        std::cout<<ans<<std::endl;
    }
    return 0;
}
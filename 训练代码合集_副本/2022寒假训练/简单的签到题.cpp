#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=26;
long long rem[N+2];
std::string mapp;

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        mapp.clear();
        std::cin>>mapp;
        for (long long j=0;j<(long long)mapp.size();j++) {
            rem[mapp[j]-'a'+1]++;
        }
    }

    long long ans=0;
    for (long long i=1;i<=26;i++) if (rem[i]%2==1) ans++;
    std::cout<<ans<<std::endl;
    ans=0;
    for (long long i=1;i<=26;i++) if (rem[i]%2==0 && rem[i]) ans++;
    std::cout<<ans<<std::endl;

    return 0;
}
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

long long n,m,ans;
std::string mapp[105];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        ans=0;
        std::cin>>n>>m;
        for (long long i=1;i<=n;i++) {
            std::cin>>mapp[i];
        }
        for (long long i=2;i<=n;i++) {
            if (mapp[i]==mapp[1]) ans++;
        }
        std::cout<<(ans+1)<<std::endl;
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long n,l=0;
        std::cin>>n;
        long long mapp[40000];
        memset(mapp,0,sizeof(mapp));
        for (long long i=1;i<=n;i++) {
            long long a;
            std::cin>>a;
            if (a>n) l++;
            else mapp[a]++;
        }
        for (long long i=0;i<=n+1;i++) {
            if (i<=(n-l-mapp[i])) {
                std::cout<<i<<std::endl;
                break;
            }
            if (i==(n+1)) std::cout<<-1<<std::endl;
        }
    }
    return 0;
}
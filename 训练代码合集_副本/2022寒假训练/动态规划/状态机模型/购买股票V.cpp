#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=1e5;
long long mapp[N+2],f[N+2][3];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    f[0][0]=f[0][1]=-100000;
    for (long long i=1;i<=n;i++) {
        f[i][0]=f[i-1][2];
        f[i][1]=std::max(f[i-1][1],f[i-1][2]-mapp[i]);
        f[i][2]=std::max(f[i-1][2],f[i-1][1]+mapp[i]);
    }

    std::cout<<std::max(std::max(f[n][0],f[n][2]),f[n][2])<<std::endl;

    return 0;
}
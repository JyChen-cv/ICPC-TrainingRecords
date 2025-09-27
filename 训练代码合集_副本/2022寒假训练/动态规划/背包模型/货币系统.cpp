#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=3000;
long long f[N*10+2],mapp[15];

long long main()
{
    long long n,m;
    std::cin>>m>>n;
    for (long long i=1;i<=m;i++) std::cin>>mapp[i];
    for (long long i=1;i<=m;i++) {
        for (long long j=mapp[i];j<=n;j++) {
            if (j==mapp[i]) f[j]++;
            else if (f[j-mapp[i]]) f[j]+=f[j-mapp[i]];
        }
    }
    std::cout<<f[n]<<std::endl;
    return 0;
}
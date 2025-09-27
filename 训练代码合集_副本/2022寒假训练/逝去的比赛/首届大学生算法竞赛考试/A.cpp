#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=500;
long long mapp[N+2];
std::vector<long long> zu[N+2];
long long f[10005][2];

long long main()
{
    long long n,m,c;
    std::cin>>n>>m>>c;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }
    for (long long i=1;i<=n;i++) {
        long long a;
        std::cin>>a;
        zu[a].push_back(mapp[i]);
    }
    
    for (long long i=1;i<=m;i++) {
        for (long long j=0;j<=c;j++) {
            for (long long k=0;k<(long long)zu[i].size();k++) {
                if (j>=zu[i][k] && (i==1 || f[j-zu[i][k]][0])) f[j][1]=std::max(f[j][1],f[j-zu[i][k]][0]+zu[i][k]);
            }
            // std::cout<<f[j][1]<<" ";
        }
        // std::cout<<std::endl;
        for (long long j=c;j>=0;j--) {
            f[j][0]=f[j][1];
            f[j][1]=0;
        }
    }
    std::cout<<f[c][0]<<std::endl;
    return 0;
}
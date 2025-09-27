#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=100;
struct group {
    long long num;
    long long hurt;
} mapp[N+2];
long long f[N*10+2][N*5+2];

long long main()
{
    long long n,m,k;
    std::cin>>n>>m>>k;
    for (long long i=1;i<=k;i++) std::cin>>mapp[i].num>>mapp[i].hurt;

    for (long long i=1;i<=k;i++) {
        for (long long j=n;j>=mapp[i].num;j--) {
            for (long long l=m;l>mapp[i].hurt;l--) {
                f[j][l]=std::max(f[j][l],f[j-mapp[i].num][l-mapp[i].hurt]+1);
            }
        }
    }
    
    for (long long i=0;i<=m;i++)
        if (f[n][i]==f[n][m]) {
            std::cout<<f[n][m]<<" "<<std::min(m,m-i+1)<<std::endl;  //这里其实就是特判一下i==0的情况，这时候计算结果大小会超过m
            break;
        }
    return 0;
}
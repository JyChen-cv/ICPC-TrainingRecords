#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=30;
long long mapp[N+2][N+2],f[N+2][N+2];  //考虑前i家工厂，前j台机器所产生价值的最大值
long long n,m;
long long rem[N+2][N+2],ans[N+2];

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) std::cin>>mapp[i][j];
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            for (long long k=0;k<=j;k++) {
                // f[i][j]=std::max(f[i][j],f[i-1][j-k]+mapp[i][k]);
                if (f[i-1][j-k]+mapp[i][k]>f[i][j]) {
                    f[i][j]=f[i-1][j-k]+mapp[i][k];
                    rem[i][j]=j-k;
                    // std::cout<<i<<" "<<j<<" "<<k<<" "<<rem[i][j]<<std::endl;
                }
            }  
        }
    }
    
    std::cout<<f[n][m]<<std::endl;
    long long tal=0,ls=m;
    for (long long i=n;i>=1;i--) {
        tal++;
        ans[tal]=ls-rem[i][ls];
        ls=rem[i][ls];
    }
    for (long long i=1;i<=n;i++) {
        std::cout<<i<<" "<<ans[tal--]<<std::endl;
    }
    return 0;
}

//也给处理有依赖的背包提供了一点思路，因为拿第二个的基础是第一个已经拿完了，
//k的枚举有点像多重背包，但不是简单的多重背包那样，这里物品累加后的价值是变动的，有点像有依赖的背包的感觉，
//但是也和有依赖的背包不完全相同，若多个物品同时依赖一个物品就不能这样简单的看

//还是要先清楚到底哪些状态能够转移到当前状态
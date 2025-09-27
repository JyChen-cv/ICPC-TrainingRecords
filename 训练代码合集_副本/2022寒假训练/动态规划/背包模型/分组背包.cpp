#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=1000;
struct group {
    long long v;
    long long w;
} mapp[N+2][N+2];
long long s[N+2],f[N+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>s[i];
        for (long long j=1;j<=s[i];j++) {
            std::cin>>mapp[i][j].v>>mapp[i][j].w;
        }

        for (long long l=m;l>=0;l--) {
            for (long long k=1;k<=s[i];k++) {
                if (l>=mapp[i][k].v) f[l]=std::max(f[l],f[l-mapp[i][k].v]+mapp[i][k].w);
            }
        }
    }

    std::cout<<f[m]<<std::endl;

    return 0;
}

//分组背包的状态意义和01背包有所转变f[i][j]表示考虑前i组物品在j的体积之下的最大价值；由此进行类比01背包，
//这样理论上每次组内的更新都是在上一组的基础上进行的更新，符合题意
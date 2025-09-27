#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long MaxN=100;
long long n,m;
long long f[MaxN+5][MaxN+5],val[MaxN+2][MaxN+2];

inline bool read(long long& x) {
    char c=getchar();
    if (c==EOF) return 0;
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return 1;
}

void show(long long x,long long y,long long z) {
    if (x==0) return ;
    for (long long k=0;k<=y;k++) {
        if (z==f[x-1][k]+val[x][y-k]) {   //这题必须要倒序循环！！！！！！
            show(x-1,k,f[x-1][k]);
            std::cout<<x<<" "<<y-k<<std::endl;
            break;
        }
    }
    return ;
}

long long main() {
    // freopen("okok.in","r",stdin);

    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            read(val[i][j]);
            // std::cout<<val[i][j]<<std::endl;
        }
    }

    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            for (long long k=0;k<=j;k++) {
                f[i][j]=std::max(f[i][j],f[i-1][j-k]+val[i][k]);
            }
            // std::cout<<f[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    std::cout<<f[n][m]<<std::endl;
    show(n,m,f[n][m]);
    return 0;
}
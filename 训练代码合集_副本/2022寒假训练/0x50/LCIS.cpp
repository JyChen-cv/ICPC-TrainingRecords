#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

const long long MaxN=3000;
long long a[MaxN+5],b[MaxN+5];
long long f[MaxN+5][MaxN+5];

inline bool read(long long &x)
{
    char c;
    if ((c=getchar())==EOF) return 0;
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return 1;
} //慎用。。。莫名其妙挂掉的风险真的太大了

long long main()
{
    long long n=0;  //这样写快读好像必须得保证一开始n的值为0？？？？？？
    std::cin>>n;
    for (long long i=1;i<=n;i++) std::cin>>a[i];
    for (long long i=1;i<=n;i++) std::cin>>b[i];

    a[0]=b[0]=-(1<<31);
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            if (a[i]==b[j]) {
                for (long long k=0;k<j;k++) {
                    if (b[k]<b[j]) f[i][j]=std::max(f[i][j],f[i-1][k]+1);
                    // std::cout<<i<<" "<<j<<" "<<f[i][j]<<std::endl;
                }
            }
            else f[i][j]=f[i-1][j];
        }
    }
    
    long long ans=0;
    for (long long i=0;i<=n;i++) {
        ans=std::max(ans,f[n][i]);
    }
    std::cout<<ans<<std::endl;
    return 0;
}
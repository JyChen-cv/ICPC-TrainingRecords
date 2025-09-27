#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=3000;
long long a[N+2],b[N+2],f[N+2][N+2];  // 集合: 所有由第一个序列的前i个字母，和第二个序列的前j个字母构成的，且以b[j]为结尾的公共上升子序列的合集
                                // 性质: 最大值

long long main()  
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) std::cin>>a[i];
    for (long long i=1;i<=n;i++) std::cin>>b[i];
            
    long long ans=0;    
    for (long long i=1;i<=n;i++) {
        long long maxx=0;
        for (long long j=1;j<=n;j++) {
            f[i][j]=f[i-1][j];
            if (a[i]==b[j]) {
                f[i][j]=std::max(f[i][j],maxx+1);
            }
            if (b[j]<a[i]) maxx=std::max(f[i][j],maxx);
            if (i==n) ans=std::max(ans,f[n][j]);
            // std::cout<<f[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    std::cout<<ans<<std::endl;
    return 0;
}
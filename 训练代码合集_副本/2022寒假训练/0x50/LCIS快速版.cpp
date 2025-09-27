#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>

const long long MaxN=3000;
long long a[MaxN+5],b[MaxN+5];
long long f[MaxN+5][MaxN+5];

long long main()
{
    long long n=0;  //这样写快读好像必须得保证一开始n的值为0？？？？？？
    std::cin>>n;
    for (long long i=1;i<=n;i++) std::cin>>a[i];
    for (long long i=1;i<=n;i++) std::cin>>b[i];

    a[0]=b[0]=-(1<<31);
    for (long long i=1;i<=n;i++) {
        long long maxx=0;
        if (b[0]<a[i]) maxx=f[i-1][0];
        for (long long j=1;j<=n;j++) {
            if (a[i]==b[j]) {  //从这里优化，a_i为定值，所以b_j也为定值
                f[i][j]=maxx+1;
            }
            else f[i][j]=f[i-1][j];
            if (b[j]<a[i]) maxx=std::max(maxx,f[i-1][j]);
        }
    }
    
    long long ans=0;
    for (long long i=0;i<=n;i++) {
        ans=std::max(ans,f[n][i]);
    }
    std::cout<<ans<<std::endl;
    return 0;
}
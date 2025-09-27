#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=300;
long long f[N+2][32];

long long main()
{
    f[0][0]=1;
    for (long long i=1;i<=30;i++) {
        for (long long j=99;j>=0;j--) {
            f[0][i]+=f[j][i-1]; 
        }
        for (long long j=100;j>=1;j--) {
            f[j][i]=f[j-10][i-1];
        }
        // for (long long j=0;j<=30;j++) {
        //     std::cout<<f[j][i]<<" ";
        // }
        // std::cout<<std::endl;
    }
    std::cout<<f[70][30]<<std::endl;
    return 0;
}
// 利用状态机模型进行计算 一个状态不再表示一个结果，而是表示一个状态， 多个状态产生一个结果
// 这道题目就是一个显然的例子：我们其实并不需要去记录到底哪天买入，从而在卖出时知道差值，其实本质上
// 这是一个差分序列，所以只需要和前一天做差即可

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N=100000,M=100;
long long mapp[N+2],f[N+2][M+2][2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];

    memset (f,-0x3f,sizeof(f));
    for (long long i=0;i<=n;i++) f[i][0][0]=0;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            f[i][j][0]=std::max(f[i-1][j][0],f[i-1][j][1]+mapp[i]);
            f[i][j][1]=std::max(f[i-1][j][1],f[i-1][j-1][0]-mapp[i]);
        }
    }

    long long ans=0;
    for (long long i=0;i<=m;i++) ans=std::max(ans,f[n][i][0]);
    std::cout<<ans<<std::endl;
    return 0;
}
// 高精度的题目一定是先用普通代码过了样例，然后再把相应的部分替换为高精度

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=100;
long long mapp[N+2],f[N+2][N+2];

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
        mapp[i+n]=mapp[i];
    }

    long long ans=0x3f3f3f3f;
    memset (f,0x3f,sizeof(f));
    for (long long i=1;i+1<=n*2;i++) f[i][i+1]=0;
    for (long long len=3;len<=n;len++) {
        for (long long l=1;l+len-1<=n*2;l++) {   //这道题目不是环形dp，因为不论从哪里开始枚举，答案都不会改变
            long long r=l+len-1;
            for (long long k=l+1;k<r;k++) {
                f[l][r]=std::min(f[l][r],f[l][k]+f[k][r]+mapp[l]*mapp[k]*mapp[r]);
            }
            if (len==n) ans=std::min(ans,f[l][r]);
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}
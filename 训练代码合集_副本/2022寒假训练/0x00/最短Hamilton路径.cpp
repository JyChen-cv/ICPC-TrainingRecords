#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long MaxN=1<<21;
long long f[MaxN+1][21],mapp[22][22];

inline bool read(long long & x) 
{
    char c=getchar();
    if (c==EOF) return 0;
    while (c<'0' || c>'9') c=getchar();
    while (c>='0' && c<='9') {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return 1;
}

long long main() 
{
    // freopen("okok.in","r",stdin);

    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            read(mapp[i][j]);
            // std::cout<<mapp[i][j]<<" ";
        }
        // std::cout<<std::endl;
    }

    // f[2][0]=0; //第一个位置一直就有
    // for (long long i=1;i<=n;i++) { //走了几步
    //     for (long long j=2;j<=(1<<(n+1))-1;j++) { //注意是n+1
    //         for (long long k=2;k<=n-1;k++) { //要走到哪个位置
    //             if (j&(1<<k)==0) continue;
    //             else {
    //                 f[j][i]=std::max(f[j][i],f[j-(1<<k)][i-1]+mapp[][k]);
    //             }
    //         }
    //     }
    // }  //这样设计状态不能满足计算，不知道是从哪里走到k的，没必要知道走了几步，知道现在有几个1.就能数出来几步，状态设计重复

    //f[i][j]，i表示状态压缩的那一维，j表示当前位置
    memset(f,0x3f,sizeof(f));
    f[2][1]=0;
    f[3][1]=0;
    for (long long i=2;i<=(1<<(n+1))-1;i+=1) {  //虽然这个计算逻辑不太符合人脑的一步算完算两步，但是却巧妙的满足dp由小到大的逻辑
        for (long long j=1;j<n;j++) {
            if ((i&(1<<j))==0) continue;
            // if ((i&2)==0) continue;
            for (long long k=2;k<=n;k++) {
                if ((i&(1<<k))!=0) continue;
                f[i+(1<<k)][k]=std::min(f[i+(1<<k)][k],f[i][j]+mapp[j][k]);
                // std::cout<<i<<" "<<j<<" "<<k<<" "<<i+(1<<k)<<" "<<f[i+(1<<k)][k]<<std::endl;
            }
        }   
    }

    std::cout<<f[(1<<(n+1))-1][n]<<std::endl;

    return 0;
}

//感觉状态压缩dp还是比较神奇，通过改变枚举方式来减少运算量，这种枚举方式思路新奇，这道题目对我有一点点启发
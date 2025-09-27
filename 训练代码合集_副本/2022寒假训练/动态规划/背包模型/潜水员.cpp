#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long MaxN=10000;
struct group {
    long long O;
    long long N;
    long long wei;
} mapp[MaxN+2];
long long f[1002][22][82];  //感觉求最小值不太好压缩空间
long long n,m,k;

long long main()
{
    std::cin>>m>>n>>k;
    for (long long i=1;i<=k;i++) {
        std::cin>>mapp[i].O>>mapp[i].N>>mapp[i].wei;
    }

    memset (f,0x3f,sizeof(f));
    // for (long long i=0;i<=m;i++) 
        // for (long long j=0;j<=n;j++) f[0][i][j]=0;
    f[0][0][0]=0;
    for (long long i=1;i<=k;i++) {
        for (long long j=m;j>=0;j--) {
            for (long long l=n;l>=0;l--) {
                f[i][j][l]=f[i-1][j][l];  //注意这一步不要拉下
                long long a=j-mapp[i].O;
                long long b=l-mapp[i].N;
                if (a<0) a=0;   //小于0的情况是合法的（看作是所带资源大于需求）  ！！！
                if (b<0) b=0;   //把它置为0，含义是指选择当前这一个罐子所产生的代价  ！！！
                f[i][j][l]=std::min(f[i][j][l],f[i-1][a][b]+mapp[i].wei);
            }
        }
    }

    std::cout<<f[k][m][n]<<std::endl;
    return 0;
}
/*

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long MaxN=10000;
struct group {
    long long O;
    long long N;
    long long wei;
} mapp[MaxN+2];
long long f[22][82];  //感觉求最小值不太好压缩空间
long long n,m,k;

long long main()
{
    std::cin>>m>>n>>k;
    for (long long i=1;i<=k;i++) {
        std::cin>>mapp[i].O>>mapp[i].N>>mapp[i].wei;
    }

    memset (f,0x3f,sizeof(f));
    // for (long long i=0;i<=m;i++) 
        // for (long long j=0;j<=n;j++) f[0][i][j]=0;
    f[0][0]=0;
    for (long long i=1;i<=k;i++) {
        for (long long j=m;j>=0;j--) {
            for (long long l=n;l>=0;l--) {
                long long a=j-mapp[i].O;
                long long b=l-mapp[i].N;
                if (a<0) a=0;   //小于0的情况是合法的（看作是所带资源大于需求）
                if (b<0) b=0;   //把它置为0，含义是指选择当前这一个罐子所产生的代价
                f[j][l]=std::min(f[j][l],f[a][b]+mapp[i].wei);
            }
        }
    }

    std::cout<<f[m][n]<<std::endl;
    return 0;
}

*/
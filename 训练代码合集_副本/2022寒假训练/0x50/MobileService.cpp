#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long MaxN=200;
long long mapp[MaxN+5][MaxN+5],dis[1003];
long long f[MaxN+2][MaxN+2][MaxN+2];

inline long long qread() {
    long long x=0,typ=1;
    char ch=getchar();
    while (ch<'0' || ch>'9') {
        if (ch=='-') typ=-1;
        ch=getchar();
    }
    while (ch>='0' && ch<='9') {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*typ;
}

long long main()
{
    freopen("okok.in","r",stdin);
    long long n,m;
    std::cin>>m>>n;
    for (long long i=1;i<=m;i++) {
        for (long long j=1;j<=m;j++) {
            mapp[i][j]=qread();
        }
    }
    for (long long i=1;i<=n;i++) dis[i]=qread();
    // std::cout<<n<<" "<<m<<std::endl;

    memset(f,0x3f,sizeof(f));
    f[0][2][3]=0;
    // f[0][3][2]=0;
    // f[0][2][1]=0;
    // f[0][1][2]=0;
    // f[0][1][3]=0;
    // f[0][3][1]=0;
    dis[0]=1;
    long long ans=-1;
    for (long long i=0;i<=n;i++) {  //这里注意灵活转换，把由上一个推到这一个变成有着一个推到下一个！！！
        // for (long long j=1;j<=m;j++) {
        //     for (long long k=1;k<=m;k++) {
        //         if (j==k || j==dis[i] || k==dis[i]) continue;
        //         f[i+1][j][k]=std::min(f[i+1][j][k],f[i][j][k]+mapp[dis[i]][dis[i+1]]);
        //         f[i+1][j][k]=std::min(f[i+1][j][k],f[i][dis[i]][k]+mapp[j][dis[i+1]]);
        //         f[i+1][j][k]=std::min(f[i+1][j][k],f[i][j][dis[i]]+mapp[k][dis[i+1]]);
        //         if ((i+1)==n) ans=std::max(ans,f[i+1][j][k]);
        //     }
        // }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
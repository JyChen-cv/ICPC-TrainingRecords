#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long MaxN=200;
long long mapp[MaxN+5][MaxN+5],dis[1003];
long long f[MaxN+2][MaxN+2][MaxN+2];
long long n,m,ans=0;

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

void dfs(long long x,long long y,long long z)
{
    // std::cout<<x<<" "<<y<<" "<<z<<std::endl;
    if (x==n) {
        ans=std::min(ans,f[x][y][z]);
        return ;
    }

    long long tag1=0,tag2=0,tag3=0;
    if (f[x+1][y][z]!=0x3f3f3f3f) tag1=1;
    if (f[x+1][dis[x]][z]!=0x3f3f3f3f) tag2=1;
    if (f[x+1][y][dis[x]]!=0x3f3f3f3f) tag3=1;
    // std::cout<<f[x+1][y][z]<<" "<<0x3f3f3f3f<<" "<<tag3<<std::endl;

    if (dis[x+1]!=y && dis[x+1]!=z && y!=z && tag1==0)
        f[x+1][y][z]=std::min(f[x+1][y][z],f[x][y][z]+mapp[dis[x]][dis[x+1]]);
    if (dis[x+1]!=dis[x] && dis[x+1]!=z && dis[x]!=z && tag2==0)
        f[x+1][dis[x]][z]=std::min(f[x+1][dis[x]][z],f[x][y][z]+mapp[y][dis[x+1]]);
    if (dis[x+1]!=y && dis[x+1]!=dis[x] && y!=dis[x] && tag3==0)
        f[x+1][y][dis[x]]=std::min(f[x+1][y][dis[x]],f[x][y][z]+mapp[z][dis[x+1]]);
    if (dis[x+1]!=y && dis[x+1]!=z && y!=z && tag1==0) dfs(x+1,y,z);
    if (dis[x+1]!=dis[x] && dis[x+1]!=z && dis[x]!=z && tag2==0) dfs(x+1,dis[x],z);
    if (dis[x+1]!=y && dis[x+1]!=dis[x] && y!=dis[x] && tag3==0) dfs(x+1,y,dis[x]);
    return ;
}

long long main()
{
    freopen("okok.in","r",stdin);
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
    dis[0]=1;
    ans=0x3f3f3f3f;
    dfs(0,2,3);
    std::cout<<ans<<std::endl;
    return 0;
}
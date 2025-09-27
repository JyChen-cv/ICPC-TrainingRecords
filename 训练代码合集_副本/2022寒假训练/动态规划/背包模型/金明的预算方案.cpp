// 这里有些不同的思路，先写在这里：
// 思路1：由于题目的设定，相当于这是一棵棵很浅的树，所以直接枚举，转换成01背包，每一棵树，是一个背包组
//       里面枚举了各种情况
// 思路2：我希望能够用到刚才的树上dp，相当于直接建立一个虚根，把森林连接成为一颗树木，然后在虚根上跑树上dp；
// 暂时未分析两者的时间复杂度

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>

const long long N=32000;
const long long M=61;
struct group {
    long long v;
    long long w;
} mapp[M+2];
long long ver[N+2],nxt[N+2],head[N+2],tot;
long long n,m,root=61;
long long f[M+2][N+2];
long long mo[M+2],mmm[N+2];

void add(long long x,long long y)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(long long x)
{
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        dfs(son);

        for (long long j=m-mapp[x].v;j>=0;j--) {
            for (long long k=0;k<=j;k++) {
                f[x][j]=std::max(f[x][j],f[x][j-k]+f[son][k]);
            }
        }
    }

    for (long long i=m;i>=mapp[x].v;i--) f[x][i]=f[x][i-mapp[x].v]+mapp[x].w;
    for (long long i=0;i<mapp[x].v;i++) f[x][i]=0;
}

long long main()
{
    std::cin>>m>>n;
    for (long long i=1;i<=n;i++) {
        long long ls;
        std::cin>>mapp[i].v>>mapp[i].w>>ls;
        mo[i]=mapp[i].v;
        mapp[i].w*=mapp[i].v;
        if (ls!=0) add(ls,i);
        else add(root,i);
        
    }

    dfs(root);
    
    std::cout<<f[root][m]<<std::endl;
    return 0;
}

// 思路2:超时，考虑使用离散化进行优化。。。未完成。。。不太好离散化操作吧。。。m也需要变
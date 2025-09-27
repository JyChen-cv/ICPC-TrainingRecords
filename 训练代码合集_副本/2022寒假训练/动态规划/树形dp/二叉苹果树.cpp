#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=200;
const long long M=30000;
long long nxt[N+2],head[N+2],ver[N+2],tot,w[N+2];
long long n,m,f[N+2][M+2];

void add(long long x,long long y,long long z)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    w[tot]=z;
}

void dfs(long long x,long long fa,long long ww) 
{
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;

        dfs(son,x,w[i]);
        for (long long j=m-1;j>=0;j--) {   
            for (long long k=0;k<=j;k++) {    // 能给到子树的最大体积
                f[x][j]=std::max(f[x][j],f[x][j-k]+f[son][k]);
            }
        }
    }
    for (long long i=m;i>=1;i--) f[x][i]=f[x][i-1]+ww;
    f[x][0]=0;
}

long long main()
{
    std::cin>>n>>m;
    // m=n-m;
    m++;  //边和点的关系。。。点总是比边多一个
    for (long long i=1;i<n;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dfs(1,-1,0);
    std::cout<<f[1][m]<<std::endl;
    return 0;
}

// 这道题目其实本质就是可以看作一个简化版的有依赖的背包问题，只不过所有的物品体积都是1，其实这个也引发我的好多思考
// 比如这样就可以完全按照性价比来贪心？反证我这么直接魔改肯定是麻烦了。。。
// 我这里用了一个边转化为点的思路，把边的价值直接赋给结尾的点，这样来了一下转换，然后跑了一遍树上的分组背包
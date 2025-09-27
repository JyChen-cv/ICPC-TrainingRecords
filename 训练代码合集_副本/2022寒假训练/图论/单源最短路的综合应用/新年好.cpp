// 这个贪心用交换法或者说调整法很容易证明正确性
// 我想法是每次找到最近的未到达的点去跑，由于是双向道路，这就保证了这个贪心的正确性
// 换句话说，a->b 的时间和b->a的时间是完全相同的

// 老师的思路是先预处理出6个点出发到各个点的单源最短路径，再枚举摆放顺序
// 给我们带来了很多思考，在想完一个代码的全部思路之后，如果发现时间复杂度不能接受，那么不妨尝试一下优化，调换顺序
// 或者是用上次最长公共上升子序列的思路来优化，等等。。。相信自己有一定的优化能力

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <map>

const long long N=50000,M=100000;
long long kk[6],tot,rem[6],ans;
long long head[N+2],nxt[M+2],ver[M+2],edge[M+2];
long long d[N+2],v[N+2];
std::queue<long long> q;

void add(long long x,long long y,long long z)
{
    tot++;
    ver[tot]=y;
    edge[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}

void SPFA(long long p)
{
    memset (d,0x3f,sizeof(d));
    memset (v,0,sizeof(v));

    d[p]=0;
    v[p]=1;
    q.push(p);
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            long long z=edge[i];
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                if (!v[y]) {
                    q.push(y);
                    v[y]=1;
                }
            }
        }
    }
}

void dfs(long long x,long long num)
{
    
    if (num==0) return ;
    SPFA(x);
    long long tag=0x3f3f3f3f,ls=0;;
    for (long long i=1;i<=5;i++) {
        if (!rem[i]) {
            if (d[kk[i]]<tag) {
                tag=d[kk[i]];
                ls=i;
            }
        }
    }
    rem[ls]=1;
    ans+=tag;
    std::cout<<ls<<" "<<num<<" "<<ans<<std::endl;
    dfs(kk[ls],num-1);
}

long long main()
{
    freopen("data.in","r",stdin);

    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=5;i++) std::cin>>kk[i];
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dfs(1,5);
    std::cout<<ans<<std::endl;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const long long N=1000,M=20000;
long long n,m,k,tot;
long long head[N+2],edge[M+2],ver[M+2],nxt[M+2],d[N+2];
std::queue<long long> q;
bool v[N+2];

void add(long long x,long long y,long long z)
{
    ver[++tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void spfa(long long polong long,long long std)
{
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[polong long]=0;
    v[polong long]=1;
    q.push(polong long);
    while (q.size()) {
        // std::cout<<q.size();
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i;i=nxt[i]) {
            long long y=ver[i];
            long long z=(edge[i]>std ? 1:0);
            if (d[y]>d[x]+z) {
                d[y]=d[x]+z;
                if (!v[y]) q.push(y),v[y]=1;
            }
        }
    }
}

bool check(long long x)
{
    spfa(1,x);
    if (d[n]<=k) return 1;
    else return 0;
}

long long main()
{
    std::cin>>n>>m>>k;
    for (long long i=1;i<=m;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    long long l=0,r=1000001;
    while (l<r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            r=mid;
        }
        else l=mid+1;
        // std::cout<<l<<" "<<r<<std::endl;
    }
    if (r==1000001) std::cout<<"-1"<<std::endl;
    else std::cout<<r<<std::endl;

    return 0;
}

// 让我的第一反应尽然是在图上进行dp转移。。。然后我便否定了这种想法。。。太tm难写了吧也。。。
// 然后我的想法是dp本质也是图论嘛，所以想通过建立一些边来帮助我完成这个想法

// 这个想法是正确的，就是这种感觉，有个名词叫做分层图
// 但是这道题目也满足一些特定的条件，所以可以使用二分答案来做，这样可以直接把一个计算问题转换为一个判断问题

// 具体做法是（这个具体做法也很难想） 把价格升级大于mid的电缆长度看作1，把省级价格不超过mid的电览长度看作0，然后求从1-n的最短路，不超过k即可
// 特定条件我猜想是 答案的分布一定需要满足单调性，一定在某种程度上有着排列关系，换句话说在无规律的数列上二分是没有意义的

// 可以使用双端队列来处理只有0和1的搜索图
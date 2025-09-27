// 相比于树上dp的思路，我更觉得应该强调一下关于两次遍历求解答案的思路的证明，以及局限性的证明
// 当有负数边权的时候，因该理性的意识到不能！！！
// 关于树形dp，我好像思路老是被根节点卡住。。。以后多加练习吧
// 感觉传统方法的两次遍历有点涉及到换根dp了。。。确实难想

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=10000;
long long ver[N*2+2],nxt[N*2+2],head[N*2+2],tot,w[N*2+2];
long long ans=0;

void add(long long x,long long y,long long z)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    w[tot]=z;
}

// 这里的枚举思路其实是，经过一个点的最长路径只有两种方式
// 要么由孩子->自己->孩子，要么孩子->自己->父亲，所以只要枚举这两种可能就可以了
// 这也启发我们，思考dp的状态转移的时候，往往需要考虑一个最小的单元，而在树上，一个节点就是一个最小的单元
// 和这个单元有关的节点，就只有两类，老的和小的，当然包括有祖宗，爷爷，孙子。。。

long long dfs(long long x,long long fa) {
    long long d1=0,d2=0;
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;
        long long ls=dfs(son,x)+w[i];
        if (ls>=d1) {
            d2=d1;
            d1=ls;
        }
        else if (ls>d2) {
            d2=ls;
        }
        ans=std::max(ans,d1+d2);
    }
    return d1;
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<n;i++) {
        long long a,b,c;
        std::cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }

    dfs(1,-1);
    std::cout<<ans<<std::endl;
    return 0;
}
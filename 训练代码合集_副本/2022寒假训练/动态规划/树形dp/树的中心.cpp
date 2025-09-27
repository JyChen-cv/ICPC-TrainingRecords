#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=10000;
long long ver[N*2+2],nxt[N*2+2],head[N*2+2],w[N*2+2],tot;
long long d1[N+2],d2[N+2],rem[N+2],ans=0x3f3f3f3f;

void add(long long x,long long y,long long z)
{
    tot++;
    w[tot]=z;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

long long dfs(long long x,long long fa)   // 找到任意一个节点的所有孩子中的前两长距离
{
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;
        long long ls=dfs(son,x)+w[i];
        if (ls>=d1[x]) {
            d2[x]=d1[x];
            d1[x]=ls;
            rem[x]=son;  // !
        }
        else if (ls>d2[x]) d2[x]=ls;
    }
    return d1[x];
}

// 找到任意一个节点的所有孩子和父亲链中的前两长的距离
// 要注意的就是要标记哪一个是最长的边，来避免重复走一个子节点
long long dfs2(long long x,long long fa,long long down)  // 记录一个我想传下去的值
{
    if (down>=d1[x]) {
        d2[x]=d1[x];
        d1[x]=down;
        rem[x]=fa;
    }
    else if (down>d2[x]) {
        d2[x]=down;
    }

    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;
        if (son==rem[x]) {
            dfs2(son,x,d2[x]+w[i]);
        }
        else {
            dfs2(son,x,d1[x]+w[i]);
        }
    }
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
    dfs2(1,-1,0);

    for (long long i=1;i<=n;i++) ans=std::min(ans,d1[i]);
    std::cout<<ans<<std::endl;

    return 0;
}

// 这道题目是一个典例，展示了从父亲更新儿子的操作
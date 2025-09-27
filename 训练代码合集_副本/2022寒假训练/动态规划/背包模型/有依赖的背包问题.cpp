#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long N=1000;
long long n,m,tot,ver[N+2],nxt[N+2],head[N+2];
struct group {
    long long v;
    long long w;
} mapp[N+2];
long long f[N+2][N+2],root;

void add(long long x,long long y)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(long long x)
{
    for (long long i=head[x];i;i=nxt[i]) {  //这里不是把树根看成物品组，是把每一颗子树看成一个物品组！！！
        long long son=ver[i];  
        dfs(son);         //遍历树

        for (long long j=m-mapp[x].v;j>=0;j--) {   //倒叙枚举空间，相当于压缩了一维
            for (long long l=0;l<=j;l++) {      //枚举子树用了多少空间
                f[x][j]=std::max(f[x][j],f[x][j-l]+f[son][l]);
            }
        }
    }

    for (long long i=m;i>=mapp[x].v;i--) f[x][i]=f[x][i-mapp[x].v]+mapp[x].w;  //这里是直接赋值，选儿子的前提就是选爸爸
    for (long long i=0;i<mapp[x].v;i++) f[x][i]=0;   //这里也是直接赋值
}

// 这道题目体现了背包的精髓，也是dp的精髓，合理利用记忆化来简化计算的时间和空间复杂度，这道题目正是通过分组背包的巧妙思想
// 把这个原本2^n的数量级的讨论问题来简化成为了可以接受的计算
// 用一个状态多的表示内容，同时还需要让状态能够维护，这两点缺一不可，如果状态设计不够优秀，极端举例就好像是暴力搜索
// 如果一个状态设计的太过于感概度高，那就变的非常不好求解，变得难以维护，同时无法满足解决题目的需求

// 这道题目还是一个树上dp，这次算是入门，树上dp其实主要的区别是更新顺序的不同，相比于普通dp，我反而觉得这种dp更加形象化
// 反而更好理解，但是套路还是远远达不到熟练，所以当然需要在树上dp的时候再多加练习

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        long long ls;
        std::cin>>mapp[i].v>>mapp[i].w>>ls;
        if (ls!=-1) add(ls,i);
        else root=i;
    }

    dfs(root);

    std::cout<<f[root][m];
    return 0;
}
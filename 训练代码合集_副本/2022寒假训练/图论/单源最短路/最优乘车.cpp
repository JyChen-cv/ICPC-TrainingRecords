#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>

const long long N = 500, M = 50000;
long long head[N + 2], nxt[M + 2], ver[M + 2];
long long num, n,t;
char cc[M+2];
long long d[N + 2], v[N + 2], mapp[N + 2][N + 2];
std::queue<long long> q;

void add(long long x, long long y)
{
    ver[++t]=y;
    nxt[t]=head[x];
    head[x]=t;
}

void spfa()
{
    memset(d, 0x3f, sizeof(d));
    memset(v, 0, sizeof(v));
    d[1] = 0;
    v[1] = 1;
    q.push(1);
    while (q.size())
    {
        long long x = q.front();
        q.pop();
        v[x] = 0;
        for (long long i = head[x]; i; i = nxt[i])
        {
            long long y = ver[i];
            if (d[y] > d[x] + mapp[x][y])
            {
                d[y] = mapp[x][y] + d[x];
                if (!v[y])
                {
                    q.push(y);
                    v[y] = 1;
                }
            }
        }
    }
}

long long main()
{
    memset(mapp, 0x3f, sizeof(mapp));

    std::cin >> num >> n;
    char c=getchar();
    long long tot=0;
    while ((c=getchar())!=EOF) {
        cc[++tot]=c;
    }
    cc[++tot]='\n';
    std::vector<long long> ls;
    ls.clear();
    long long a=0;
    for (long long i=1;i<=tot;i++) {
        if (cc[i]<'0' || cc[i]>'9') {
            if (cc[i]=='\n') {
                if (a) {
                    ls.push_back(a);
                    a=0;
                }
                // std::cout<<ls[(long long)ls.size()-1]<<std::endl;
                for (long long j=0;j<(long long)ls.size();j++) {
                    for (long long l=0;l<(long long)ls.size();l++) {
                        mapp[ls[j]][ls[l]]=1;
                        add(ls[j],ls[l]);
                    }
                }
                ls.clear();
            }
            else {
                ls.push_back(a);
                a=0;
            }
        }
        else {
            a*=10;
            a+=(cc[i]-'0');
        }
    }

    spfa();
    if (d[n] != 0x3f3f3f3f)
        std::cout << std::max(d[n]-1,0) << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}

// 这道题目有趣在描述的是边和边的关系，而不是点和点的关系，比较具有迷惑性。
// 换句话说，点和点之间转移永远不会产生代价，但是边和边转移需要代价，可以考虑边点互换。。。一个我脑补出来的神奇操作

// 听完y总的讲解，感觉自己想的太复杂了，直接把同一条线路上的任意两个车站之间互相建立边就可以了
// 太巧妙了

// 边的权重都是1，所以没必要用最短路算法，直接bfs即可解决
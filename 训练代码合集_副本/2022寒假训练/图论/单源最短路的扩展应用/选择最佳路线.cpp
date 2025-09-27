#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

const long long M=200000,N=1000;
long long head[N+2],edge[M+2],nxt[M+2],ver[M+2];
long long tot,d[N+2],v[N+2];
long long n,m,s,w,mapp[N+2];
std::queue<long long> q;

void add(long long x,long long y,long long z)
{
    tot++;
    nxt[tot]=head[x];
    head[x]=tot;
    ver[tot]=y;
    edge[tot]=z;
}

void spfa() {   // 思路一：把所有可能的源头都作为源点来跑spfa
    memset (d,0x3f,sizeof(d));
    memset (v,0,sizeof(v));
    for (long long i=1;i<=w;i++) {
        d[mapp[i]]=0;
        v[mapp[i]]=1;
        q.push(mapp[i]);
    }
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

void spfa(long long x) {  // 思路二：建立虚拟原点，跑spfa，注意赋值-1
    memset (d,0x3f,sizeof(d));
    memset (v,0,sizeof(v));
    d[0]=0;
    v[0]=1;
    q.push(0);
    while (q.size()) {
        long long x=q.front();
        q.pop();
        v[x]=0;
        for (long long i=head[x];i!=-1;i=nxt[i]) {
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

long long main()
{
    while (std::cin>>n) {
        memset (nxt,-1,sizeof(nxt));
        memset (head,-1,sizeof(head));
        tot=0;
        std::cin>>m>>s;
        for (long long i=1;i<=m;i++) {
            long long a,b,c;
            std::cin>>a>>b>>c;
            add(a,b,c);
        }
        std::cin>>w;
        for (long long i=1;i<=w;i++) {
            std::cin>>mapp[i];
            // add(0,mapp[i],0);
        }
        spfa();
        if (d[s]!=0x3f3f3f3f) std::cout<<d[s]<<std::endl;
        else std::cout<<-1<<std::endl;
    }

    return 0;
}
// 思路三：反向建立图，从结果出发找最小
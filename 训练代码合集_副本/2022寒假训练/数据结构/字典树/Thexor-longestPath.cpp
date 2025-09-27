#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
long long tot,ver[N*2+2],head[N+2],edge[N*2+2],nxt[N*2+2];
long long d[N+2];
long long tt,trie[32*N][2];

void add(long long x,long long y,long long z) {
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
    edge[tot]=z;
}

void dfs(long long x,long long fa) {
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        long long z=edge[i];
        if (y==fa) continue;
        d[y]=d[x]^z;
        dfs(y,x);
    }
}

void insert(long long x) {
    long long p=1;
    for (long long i=31;i>=0;i--) {
        long long ch=(x>>i)&1;
        if (!trie[p][ch]) {
            trie[p][ch]=++tt;
        }
        p=trie[p][ch];
    }
}

long long deal(long long x) {
    long long p=1,res=0;
    for (long long i=31;i>=0;i--) {
        long long ch=(x>>i)&1;
        if (trie[p][ch^1]) {
            p=trie[p][ch^1];
            res<<=1;
            res+=ch^1;
        }
        else {
            p=trie[p][ch];
            res<<=1;
            res+=ch;
        }
    }
    return res;
}

long long main()
{
    long long n;
    while (std::cin>>n) {
        memset (ver,0,sizeof(ver));
        memset (head,0,sizeof(head));
        memset (nxt,0,sizeof(nxt));
        memset (d,0,sizeof(d));
        memset (edge,0,sizeof(edge));
        tot=0;
        memset (trie,0,sizeof(trie));
        tt=1;
        
        for (long long i=1;i<n;i++) {
            long long a,b,c;
            std::cin>>a>>b>>c;
            add(a+1,b+1,c);
            add(b+1,a+1,c);
        }
        dfs(1,0);
        long long ans=0;
        for (long long i=1;i<=n;i++) {
            insert(d[i]);
            ans=std::max(ans,d[i]^deal(d[i]));
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
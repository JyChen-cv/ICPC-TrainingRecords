#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const long long N=100000;
long long s[N+2],ver[N+2],head[N+2],nxt[N+2],tag[N+2],tot,deep[N+2];
long long root,rem;

void add(long long x,long long y)
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(long long x,long long fa)
{
    if (deep[x]>rem) {
        rem=deep[x];
        root=x;
    }
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;
        deep[son]=deep[x]+1;
        dfs(son,x);
    }
}

long long dfs2(long long x,long long fa)
{
    long long ls=0;
    for (long long i=head[x];i;i=nxt[i]) {
        long long son=ver[i];
        if (son==fa) continue;
        ls=std::max(ls,dfs2(son,x)+1);
    }
    return ls;
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        for (long long j=2;j*i<=n;j++) {
            s[j*i]+=i;
        }
    }

    // memset (head,-1,sizeof(head));
    for (long long i=2;i<=n;i++) {
        if (i>s[i]) {
            add(i,s[i]);
            add(s[i],i);
        }
    }

    long long ans=0;
    memset (deep,-1,sizeof(deep));
    for (long long i=1;i<=n;i++) {
        if (deep[i]<=0) {
            root=0;
            rem=-1;
            deep[i]=0;
            dfs(i,-1);

            long long ls=dfs2(root,-1);
            ans=std::max(ans,ls);
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=5000;
long long cnt[N+2],nxt[N*2+2],head[N+2],ver[N*2+2],tot;
long long ans[N+1][N+1],answer;

void add(long long x,long long y) 
{
    tot++;
    ver[tot]=y;
    nxt[tot]=head[x];
    head[x]=tot;
}

void dfs(long long x,long long fa)
{
    ans[x][cnt[x]]++;
    for (long long i=head[x];i;i=nxt[i]) {
        long long y=ver[i];
        if (y==fa) continue;
        dfs(y,x);
        for (long long i=1;i<=5000;i++) {
            ans[x][i]+=ans[y][i];
        }
    }
    
    long long tag=0,tag2=0;
    for (long long i=1;i<=5000;i++) {
        if (ans[x][i]) {
            if (tag==0) tag=ans[x][i];
            else if (ans[x][i]==tag) continue;
            else {
                tag2=1;
                break;
            }
        }
    }
    if (tag2==0) {
        answer++;
        // std::cout<<x<<std::endl;
    }
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long a;
        std::cin>>cnt[i]>>a;
        if (i>=2) {
            add(i,a);
            add(a,i);
        }
    }

    dfs(1,0);
    std::cout<<answer<<std::endl;
    return 0;
}
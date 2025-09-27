#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=30;
long long en[N+2],mid[N+2],tag;
std::vector<long long> ans[N+2];

void dfs(long long l,long long r,long long cnt)
{
    if (l>r) return ;
    for (long long i=l;i<=r;i++) {
        if (mid[i]==en[tag]) {
            ans[cnt].push_back(mid[i]);
            --tag;
            dfs(i+1,r,cnt+1); // 先右后左
            dfs(l,i-1,cnt+1);
            return ;
        }
    }
}

long long main()
{
    long long n;
    std::cin>>n;
    tag=n;
    for (long long i=1;i<=n;i++) std::cin>>en[i];
    for (long long i=1;i<=n;i++) std::cin>>mid[i];

    dfs(1,n,1);
    for (long long i=1;i<=n;i++) {
        if (!ans[i].size()) break;
        for (long long j=(long long)ans[i].size()-1;j>=0;j--) std::cout<<ans[i][j]<<" ";
    }
    return 0;
}
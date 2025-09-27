#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=10000;
std::vector<long long> nod[N+2];
long long w[N+2],rem[N+2],root,dp[N+2][3];

void dfs(long long x)
{
    dp[x][2]=w[x];
    for (long long i=0;i<(long long)nod[x].size();i++) {
        long long son=nod[x][i];

        dfs(son);
        dp[x][0]+=std::min(dp[son][1],dp[son][2]);
        dp[x][2]+=std::min(std::min(dp[son][0],dp[son][1]),dp[son][2]);
    }

    dp[x][1]=1e9;
    for (long long i=0;i<(long long)nod[x].size();i++) {
        long long son=nod[x][i];
        dp[x][1]=std::min(dp[x][1],dp[son][2]+dp[x][0]-std::min(dp[son][1],dp[son][2]));
    }
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        long long ls,num,lss;
        std::cin>>ls>>w[ls]>>num;
        for (long long j=1;j<=num;j++) {
            std::cin>>lss;
            rem[lss]=1;
            nod[ls].push_back(lss);
        }
    }

    for (long long i=1;i<=n;i++) {
        if (rem[i]==0) {
            root=i;
        }
    }
    dfs(root);
    std::cout<<std::min(dp[root][1],dp[root][2])<<std::endl;
    return 0;
}

// 这道题目被特例卡住了，这也警醒我，确实平时思考特例太少了。。。要多加思考，acm赛制。。。特例出现就是暴毙。。。
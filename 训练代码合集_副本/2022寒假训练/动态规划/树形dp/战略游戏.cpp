#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

const long long N=10000;
std::vector<long long> nod[N+2];
long long rem[N+2],root,dp[N+2][2];

// long long all=0,ans=0x3f3f3f3f;

// void dfs(long long x,long long tag)
// {

//     for (long long i=0;i<nod[x].size();i++) {
//         long long son=nod[x][i];
//         if (tag==0) {
//             all++;
//             dfs(son,1);
//             all--;  // 回溯
//         }
//         else {
//             dfs(son,0);
            
//             all++;
//             dfs(son,1);
//             all--;  // 回溯
//         }
//     }
// }  //超时写法。。。过于暴力了


// 这种写法的状态计算并没有减少，但是前者必定超时，后者却不会超时。。。
// 一种是树状展开，另一种却是线性计算
// 同一状态设计，同一转移思路，计算过程却天差地别
void dfs(long long x)
{
    for (long long i=0;i<nod[x].size();i++) {
        long long son=nod[x][i];
        dfs(son);
        dp[x][0]+=dp[son][1];
        dp[x][1]+=std::min(dp[son][0],dp[son][1]);
    }
    dp[x][1]++;  // 处理叶子结点的情况
}

long long main()
{
    long long n;
    while (std::cin>>n) {
        for (long long i=1;i<=n;i++) nod[i].clear();
        memset (rem,0,sizeof(rem));
        memset (dp,0,sizeof(dp));
        
        for (long long i=1;i<=n;i++) {
            long long ls,num,lss;
            scanf("%d:(%d)",&ls,&num);  // 这种写法值得学习
            for (long long j=1;j<=num;j++) {
                std::cin>>lss;
                nod[ls+1].push_back(lss+1);
                rem[lss+1]=1;
            }
        }
        for (long long i=1;i<=n;i++) {
            if (rem[i]==0) root=i;
        }

        dfs(root);
        std::cout<<std::min(dp[root][0],dp[root][1])<<std::endl;
        // for (long long i=1;i<=n;i++) std::cout<<dp[i][0]<<" "<<dp[i][1]<<std::endl;
    }

    return 0;
}
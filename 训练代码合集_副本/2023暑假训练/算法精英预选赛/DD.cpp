#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const int N=2e6;
long long dp[N+2][4],mapp[N+2][4]; //dp[2]表示2降，dp[0]表示2升

int main()
{
    int n;
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i][1]>>mapp[i][2]>>mapp[i][3];
        mapp[i+n][1]=mapp[i][1];
        mapp[i+n][2]=mapp[i][2];
    }
    for (int i=1;i<=n*2;i++) {
        dp[i][1]=std::max(dp[i-1][0],dp[i-1][3])+mapp[i][1];
        dp[i][3]=std::max(dp[i-1][2],dp[i-1][1])+mapp[i][3];
        dp[i][2]=dp[i-1][3]+mapp[i][2];
        dp[i][0]=dp[i-1][1]+mapp[i][2];
        for (int j=0;j<=3;j++) std::cout<<dp[i][j]<<" ";
        std::cout<<std::endl;
    }

    long long ans=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=3;j++) {
            ans=std::max(ans,dp[i+n][j]-dp[i][j]);
        }
        ans=std::max(ans,dp[i+n][3]-dp[i][0]);
        ans=std::max(ans,dp[i+n][0]-dp[i][3]);
        ans=std::max(ans,dp[i+n][1]-dp[i][2]);
        ans=std::max(ans,dp[i+n][2]-dp[i][1]);
    }
    std::cout<<ans<<std::endl;
    return 0;
}
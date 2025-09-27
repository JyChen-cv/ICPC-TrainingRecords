#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const int N=1e6;
long long dp[N+2][4],mapp[N+2][4],tag[N+2][4]; //dp[2]表示2降，dp[0]表示2升

int main()
{
    int n;
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i][1]>>mapp[i][2]>>mapp[i][3];
    }
    tag[1][0]=0;
    tag[1][1]=1;
    tag[1][2]=2;
    tag[1][3]=3;
    dp[1][0]=mapp[1][2];
    dp[1][1]=mapp[1][1];
    dp[1][2]=mapp[1][2];
    dp[1][3]=mapp[1][3];
    for (int i=2;i<n;i++) {
        // dp[i][1]=std::max(dp[i-1][0],dp[i-1][3])+mapp[i][1];
        if (dp[i-1][0]>dp[i-1][3]) {
            dp[i][1]=dp[i-1][0]+mapp[i][1];
            tag[i][1]=tag[i-1][0];
        }
        else if (dp[i-1][0]<=dp[i-1][3]){
            dp[i][1]=dp[i-1][3]+mapp[i][1];
            tag[i][1]=tag[i-1][3];
        }
        if (dp[i-1][2]>dp[i-1][1]) {
            dp[i][3]=dp[i-1][2]+mapp[i][3];
            tag[i][3]=tag[i-1][2];
        }
        else if (dp[i-1][2]<=dp[i-1][1]){
            dp[i][3]=dp[i-1][1]+mapp[i][3];
            tag[i][3]=tag[i-1][1];
        }
        // dp[i][3]=std::max(dp[i-1][2],dp[i-1][1])+mapp[i][3];
        dp[i][2]=dp[i-1][3]+mapp[i][2];
        tag[i][2]=tag[i-1][3];
        dp[i][0]=dp[i-1][1]+mapp[i][2];
        tag[i][0]=tag[i-1][1];
    }

    {
        if (tag[n-1][1]==1) {
            dp[n][0]=std::max(dp[n-1][1],dp[n][0]);
            dp[n][3]=std::max(dp[n-1][1],dp[n][3]);
        }
        else if (tag[n-1][1]==2) dp[n][3]=std::max(dp[n-1][1],dp[n][3]);
        if (tag[n-1][3]==0) dp[n][1]=std::max(dp[n-1][3],dp[n][1]);
        else if (tag[n-1][3]==3) {
            dp[n][1]=std::max(dp[n-1][3],dp[n][1]);
            dp[n][2]=std::max(dp[n][2],dp[n-1][3]);
        }
        if (tag[n-1][2]==0) dp[n][3]=std::max(dp[n][3],dp[n-1][2]);
        else if (tag[n-1][2]==1) dp[n][3]=std::max(dp[n][3],dp[n-1][2]);
        if (tag[n-1][0]==0) dp[n][1]=std::max(dp[n][1],dp[n-1][0]);
        else if (tag[n-1][0]==3) dp[n][1]=std::max(dp[n][1],dp[n-1][0]);
    }
    dp[n][0]+=mapp[n][2];
    dp[n][1]+=mapp[n][1];
    dp[n][2]+=mapp[n][2];
    dp[n][3]+=mapp[n][3];
    
    long long ans=0;
    for (int i=0;i<=3;i++) ans=std::max(ans,dp[n][i]);
    std::cout<<ans<<std::endl;
    return 0;
}
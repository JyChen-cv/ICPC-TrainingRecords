#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

const int N=2e5;
int dp[2][N+2][2];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n,num=1;
        std::cin>>n;
        for (int i=1;i<=n;i++) {
            dp[0][i][0]=0;
            dp[1][i][0]=0;
            dp[0][i][1]=0;
            dp[1][i][1]=0;
        }
        dp[1][1][1]=1;
        dp[1][1][0]=1;
        for (int i=1;i<=n;i++) {
            char c;
            std::cin>>c;
            if (c=='+') {
                int a,b;
                std::cin>>a>>b;
                if (b==1) {
                    dp[1][++num][1]=dp[1][a][1]+1;
                    dp[1][num][0]=std::max(dp[1][num][1],dp[1][a][0]);
                    dp[0][num][0]=dp[0][a][0];
                    dp[0][num][1]=std::min(0,dp[0][a][1]+1);
                }
                else {
                    dp[0][++num][1]=dp[0][a][1]-1;
                    dp[0][num][0]=std::min(dp[0][num][1],dp[0][a][0]);
                    dp[1][num][0]=dp[1][a][0];
                    dp[1][num][1]=std::max(0,dp[1][a][1]-1);
                }
            }
            else {
                int a,b,c;
                std::cin>>a>>b>>c;
                if (c<=dp[1][b][0] && c>=dp[0][b][0]) std::cout<<"YES"<<std::endl;
                else std::cout<<"NO"<<std::endl;
            }
        }
    }
    return 0;
}
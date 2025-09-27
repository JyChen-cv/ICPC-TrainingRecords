#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const long long Mod=1e9+7;
const int N=1e4;
long long dp[N+2][2][2];

int main()
{
    int n;
    std::cin>>n;
    dp[0][0][0]=dp[0][1][0]=1;
    for (int i=1;i<=n;i++) {
        dp[i][0][0]=(dp[i-1][0][0]+dp[i-1][0][1])%Mod;
        dp[i][0][1]=dp[i-1][0][0];
        dp[i][1][0]=(dp[i-1][1][0]+dp[i-1][1][1])%Mod;
        dp[i][1][1]=dp[i-1][1][0];
    }
    std::cout<<((dp[n][0][0]+dp[n][0][1])%Mod)*((dp[n][1][0]+dp[n][1][1])%Mod)%Mod<<std::endl;
    return 0;
}
// https://www.luogu.com.cn/problem/P4302
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

const long long N=100;
long long dp[N+2][N+2];
std::string mapp;

long long check(long long x,long long y,long long z)
{
    for (long long i=x;i+z<=y;i++) {
        if (mapp[i]!=mapp[i+z]) return 0;
    }
    return 1;
}

long long work(long long x)
{
    long long ls=1;
    while (x/=10) ls++;
    return ls;
}

long long main() 
{
    std::cin>>mapp;
    
    for (long long i=0;i<(long long)mapp.size();i++) dp[i][i]=1;
    for (long long len=2;len<=(long long)mapp.size();len++) {
        for (long long l=0;l+len-1<(long long)mapp.size();l++) {
            long long r=l+len-1;
            dp[l][r]=len;
            for (long long k=l;k<r;k++) dp[l][r]=std::min(dp[l][r],dp[l][k]+dp[k+1][r]);
            for (long long j=1;j<=len;j++) {
                if (len%j!=0) continue;
                else if (check(l,r,j)==1) dp[l][r]=std::min(dp[l][r],dp[l][l+j-1]+work(len/j)+2);
            }
        }
    }
    std::cout<<dp[0][(long long)mapp.size()-1]<<std::endl;

    return 0;
}
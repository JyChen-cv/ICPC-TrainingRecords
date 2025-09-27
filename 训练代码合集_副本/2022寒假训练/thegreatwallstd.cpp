#pragma GCC diagnostic error "-std=c++11"
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<ctime>
#define iss ios::sync_with_stdio(false)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<long long,long long> pii;
const long long mod=1e9+7;
const long long MAXN=1e4+5;
const long long inf=0x3f3f3f3f;
ll dp[2][MAXN][5];
long long a[MAXN];
long long main()
{
    freopen("data.in","r",stdin);
    freopen("std.txt","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(dp,-inf,sizeof dp);
    dp[0][0][3]=0;
    long long f=1;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){

            dp[f][j][0]=dp[f^1][j-1][3];
            dp[f][j][1]=dp[f^1][j-1][3]+a[i];
            dp[f][j][2]=dp[f^1][j-1][3]-a[i];
            dp[f][j][3]=dp[f^1][j-1][3];
            dp[f][j][0]=max(dp[f][j][0],dp[f^1][j][0]);
            dp[f][j][1]=max(dp[f][j][1],dp[f^1][j][1]);
            dp[f][j][1]=max(dp[f][j][1],dp[f^1][j][0]+a[i]);
            dp[f][j][2]=max(dp[f][j][2],dp[f^1][j][2]);
            dp[f][j][2]=max(dp[f][j][2],dp[f^1][j][0]-a[i]);
            dp[f][j][3]=max(dp[f][j][3],dp[f^1][j][3]);
            dp[f][j][3]=max(dp[f][j][3],dp[f^1][j][2]+a[i]);
            dp[f][j][3]=max(dp[f][j][3],dp[f^1][j][1]-a[i]);
        }
        f^=1;
    }
    f^=1;
    for(long long i=1;i<=n;i++){
        cout<<dp[f][i][3]<<endl;
    }
}

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long dx[9]={0,1,1,2,2,-1,-1,-2,-2};
const long long dy[9]={0,2,-2,1,-1,2,-2,1,-1};
long long mapp[12][12],n,m,t,px,py,ans;

void dfs(long long x,long long y,long long num)
{
    if (num==n*m) {
        ans++;
        return ;
    }
    for (long long i=1;i<=8;i++) {
        long long xx=x+dx[i];
        long long yy=y+dy[i];
        if (xx<1 || xx>n || yy<1 || yy>m) continue;
        if (mapp[xx][yy]) continue;
        mapp[xx][yy]=1;
        dfs(xx,yy,num+1);
        mapp[xx][yy]=0;
    }
}

long long main()
{
    std::cin>>t;
    while (t--) {
        std::cin>>n>>m>>px>>py;
        px++;
        py++;
        mapp[px][py]=1;
        ans=0;
        dfs(px,py,1);
        mapp[px][py]=0;
        std::cout<<ans<<std::endl;
    }
    return 0; 
}
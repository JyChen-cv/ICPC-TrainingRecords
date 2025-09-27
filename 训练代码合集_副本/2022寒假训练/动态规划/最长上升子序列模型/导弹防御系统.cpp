#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=50;
long long mapp[N+2],up[N+2],down[N+2],ans=0,n;

void dfs(long long now,long long len_u,long long len_d) {
    // std::cout<<now<<" "<<len_u<<" "<<len_d<<" "<<ans<<" "<<down[len_d]<<" "<<mapp[now]<<std::endl;
    if (len_u+len_d>=ans) return ; //一步极其重要的剪枝，一定要减的彻底，取等时都要剪枝掉
    if (now==n+1) {
        ans=len_u+len_d;
        return ;
    }  //上面已经排除了大于的情况，这里可以直接更新

    // 情况 1 先把当前的元素放入up数组
    if (mapp[now]>=up[len_u]) {  //根据返链定理而来，一定有等于号
        up[len_u+1]=mapp[now];
        dfs(now+1,len_u+1,len_d);
        up[len_u+1]=0;  //回溯
    }
    else {
        long long x=std::upper_bound(up+1,up+len_u+1,mapp[now])-up;
        long long ls=up[x];
        up[x]=mapp[now];
        dfs(now+1,len_u,len_d);
        up[x]=ls;  //回溯
    }
    
    // std::cout<<now<<" "<<len_u<<" "<<len_d<<" "<<ans<<" "<<down[len_d]<<" "<<mapp[now]<<std::endl;
    // 情况 2 把当前的元素放入down数组
    if (mapp[now]<=down[len_d]) {    //根据返链定理而来，一定有等于号
        down[len_d+1]=mapp[now];
        dfs(now+1,len_u,len_d+1);
        down[len_d+1]=0x3f3f3f3f;  //回溯
    }
    else {
        long long x=std::lower_bound(down+1,down+len_d+1,mapp[now],std::greater<long long>() )-down;  //根据返链定理而来，一定有等于号
        long long ls=down[x];
        down[x]=mapp[now];
        dfs(now+1,len_u,len_d);
        down[x]=ls;  //回溯
    }
}

long long main()
{
    while (1) {
        memset (mapp,0,sizeof(mapp));
        memset (up,0,sizeof(up));
        memset (down,0x3f,sizeof(down));
        ans=0x3f3f3f3f;

        std::cin>>n;
        for (long long i=1;i<=n;i++) std::cin>>mapp[i];
        if (n==0) break;
        dfs(1,0,0);

        std::cout<<ans<<std::endl;
    }

    return 0;
}
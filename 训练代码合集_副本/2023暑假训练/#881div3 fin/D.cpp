#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

const int N=2e5;
std::vector<int> mapp[N+2];
long long cnt[N+2];

void dfs(int x,int fa)
{
    // std::cout<<x<<" "<<fa<<std::endl;
    if (mapp[x].size()==1 && x!=1) {
        cnt[x]=1;
        return ;
    }
    for (int i=0;i<(int)mapp[x].size();i++) {
        if (mapp[x][i]==fa) continue;
        dfs(mapp[x][i],x);
        cnt[x]+=cnt[mapp[x][i]];
    }
}

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n;
        std::cin>>n;
        for (int i=1;i<n;i++) {
            
            int a,b;
            std::cin>>a>>b;
            mapp[a].push_back(b);
            mapp[b].push_back(a);
        }

        dfs(1,0);
        int m;
        std::cin>>m;
        for (int i=1;i<=m;i++) {
            int a,b;
            std::cin>>a>>b;
            std::cout<<(cnt[a]*cnt[b])<<std::endl;
        }
        for (int i=1;i<=n;i++) cnt[i]=0,mapp[i].clear();
    }
    return 0; 
}
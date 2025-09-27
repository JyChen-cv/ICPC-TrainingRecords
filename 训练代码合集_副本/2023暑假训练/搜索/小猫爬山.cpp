#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

const int N=20;
long long mapp[N+2],v[N+2],all,ans=100;
int n;

bool cmp(int x,int y) {
    return x>y;
}

void dfs(int x,int num) {
    if (num>ans) return ;
    if (x>n) {
        ans=num;
        return ;
    } 
    for (int i=1;i<=num;i++) {
        if (all>=v[i]+mapp[x]) {
            v[i]+=mapp[x];
            dfs(x+1,num);
            v[i]-=mapp[x];
        }
    }
    num++;
    v[num]=mapp[x];
    dfs(x+1,num);
    v[num]=0;
    num--;
}

int main()
{
    std::cin>>n>>all;
    for (int i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }
    std::sort(mapp+1,mapp+n+1,cmp);
    dfs(0,0);

    std::cout<<ans<<std::endl;
    return 0;
}
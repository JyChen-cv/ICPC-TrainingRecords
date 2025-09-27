#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

const long long N=10;
long long mapp[N+2][N+2],n,m,ans[N+2][N+2],answer;

bool check(long long x,long long y)
{
    if (mapp[x][y]==-1) return 1;
    long long ls=0;
    for (long long i=x-1;i<=x+1;i++) {
        for (long long j=y-1;j<=y+1;j++) {
            ls+=ans[i][j];
        }
    }
    if (ls==mapp[x][y]) return 1;
    else return 0;
}

void dfs(long long x,long long y)
{
    // std::cout<<x<<" "<<y<<std::endl;
    if (y>m) {
        if (x+1<=n) {
            x++;
            y=1;
        }
        else {
            // std::cout<<n<<" "<<m<<std::endl;
            for (long long i=1;i<=n;i++) {
                for (long long j=1;j<=m;j++) {
                    // std::cout<<ans[i][j]<<" ";
                    if (!check(i,j)) return ;
                }
                // std::cout<<std::endl;
            }
            answer++;
            // for (long long i=1;i<=n;i++) {
            //     for (long long j=1;j<=m;j++) {
            //         std::cout<<ans[i][j]<<" ";
            //     }
            //     std::cout<<std::endl;
            // }
            return ;
        }
    }
    ans[x][y]=0;
    dfs(x,y+1);
    ans[x][y]=1;
    dfs(x,y+1);
}

long long main()
{
    // freopen("okok.in","r",stdin);
    std::cin>>n>>m;
    // std::cout<<n<<" "<<m<<std::endl;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            char c;
            std::cin>>c;
            if (c<='9' && c>='0') {
                mapp[i][j]=(c-'0');
            }
            else mapp[i][j]=-1;
        }
    }

    dfs(1,1);
    std::cout<<answer<<std::endl;
    return 0;
}
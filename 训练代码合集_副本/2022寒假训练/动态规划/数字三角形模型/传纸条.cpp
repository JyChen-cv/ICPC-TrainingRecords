#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const long long MaxN=50;
long long mapp[MaxN+2][MaxN+2],f[MaxN*2+2][MaxN][MaxN+2];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            std::cin>>mapp[i][j];
        }
    }
    
    
    for (long long all=1;all<=n+m-1;all++) {
        for (long long x1=1;x1<=all && x1<=n;x1++) {
            for (long long x2=1;x2<=all && x2<=n;x2++) {
                long long y1=all+1-x1;
                long long y2=all+1-x2;
                f[all][x1][x2]=std::max(f[all][x1][x2],f[all-1][x1-1][x2-1]);  //这里的四种组合情况一定是2*2得来的不是2+2得来的，因为all-1一定会使得两条路的步数同时-1
                f[all][x1][x2]=std::max(f[all][x1][x2],f[all-1][x1][x2-1]);
                f[all][x1][x2]=std::max(f[all][x1][x2],f[all-1][x1-1][x2]);
                f[all][x1][x2]=std::max(f[all][x1][x2],f[all-1][x1][x2]);
                if (x1==x2 && all!=1 && all!=(n+m-1)) f[all][x1][x2]=-1000000000;
                else f[all][x1][x2]+=mapp[x1][y1]+mapp[x2][y2];
                
                // std::cout<<all<<" "<<x1<<" "<<x2<<" "<<f[all][x1][x2]<<std::endl;
            }
        }
    }

    std::cout<<f[n+m-1][n][n]-mapp[1][1]-mapp[n][m]<<std::endl;
    return 0;
}
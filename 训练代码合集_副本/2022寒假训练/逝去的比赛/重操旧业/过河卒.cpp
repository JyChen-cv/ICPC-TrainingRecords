#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long MaxN=20;
bool mapp[MaxN+2][MaxN+2];
long long ans[MaxN+2][MaxN+2];
long long a,b,c,d;

void dfs(long long x,long long y) {
    if (mapp[x][y]==0) {
        if (x>=1 && mapp[x-1][y]==0) ans[x][y]+=ans[x-1][y];
        if (y>=1 && mapp[x][y-1]==0) ans[x][y]+=ans[x][y-1];  
    }
    if (x+1<=a) dfs(x+1,y);
    else if (y+1<=b) dfs(0,y+1);
}

long long main() {
    std::cin>>a>>b>>c>>d;
    mapp[c][d]=1;

    if (c==a && d==b) {
        std::cout<<0<<std::endl;
        return 0;
    }
    if (c==0 && d==0) {
        std::cout<<0<<std::endl;
        return 0;
    }

    if (c>=2) {
        if (d>=1) mapp[c-2][d-1]=1;
        if (d<=b-1) mapp[c-2][d+1]=1;
    }
    if (c>=1) {
        if (d>=2) mapp[c-1][d-2]=1;
        if (d<=b-2) mapp[c-1][d+2]=1;
    }
    if (c<=a-2) {
        if (d>=1) mapp[c+2][d-1]=1;
        if (d<=b-1) mapp[c+2][d+1]=1;
    }
    if (c<=a-1) {
        if (d>=2) mapp[c+1][d-2]=1;
        if (d<=b-2) mapp[c+1][d+2]=1;
    }

    ans[0][0]=1;
    dfs(0,0);

    // for (long long i=0;i<=a;i++) {
    //     for (long long j=0;j<=b;j++) {
    //         std::cout<<mapp[i][j]<<" ";
    //     }
    //     std ::cout<<std::endl;
    // }
    std::cout<<ans[a][b]<<std::endl;
    return 0;
}
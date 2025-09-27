#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

const long long MaxN=1000;
const long long dx[5]={0,1,-1,0,0};
const long long dy[5]={0,0,0,1,-1};
long long mapp[MaxN+2][MaxN+2],v[MaxN+2][MaxN+2];
std::queue<std::pair<long long,long long> > bfs;

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::string a;
        std::cin>>a;
        for (long long j=0;j<(long long)a.size();j++) {
            if (a[j]=='1') {
                bfs.push(std::make_pair(i,j+1));
                v[i][j+1]=1;
            }
        }
    }

    while (bfs.size()) {
        long long x=bfs.front().first;
        long long y=bfs.front().second;
        bfs.pop();
        for (long long i=1;i<=4;i++) {
            long long xx=x+dx[i];
            long long yy=y+dy[i];
            if (xx<1 || xx>n || yy<1 || yy>m) continue;
            if (!v[xx][yy]) {
                mapp[xx][yy]=mapp[x][y]+1;
                bfs.push(std::make_pair(xx,yy));
                v[xx][yy]=1;
            }
        }
    }
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=m;j++) {
            std::cout<<mapp[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
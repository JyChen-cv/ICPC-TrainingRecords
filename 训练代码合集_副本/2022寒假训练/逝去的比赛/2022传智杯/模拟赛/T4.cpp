#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

const long long N=50;
long long ans[N+2][N+2];
std::vector<long long> mapp[N+2][N+2];
std::string line;

long long main()
{
    long long n,m,xx,yy;
    std::cin>>n>>m>>xx>>yy;
    std::cin>>line;
    // for (long long i=1;i<=n;i++) {
    //     for (long long j=1;j<=n;j++) {
    //         mapp[i][j].push_back(1);
    //     }
    // }
    for (long long i=0;i<(long long)line.size();i++) {
        mapp[xx][yy].push_back(i+1);
        if (line[i]=='E') {
            xx++;
        }
        else if (line[i]=='W') {
            xx--;
        }
        else if (line[i]=='S') {
            yy--;
        }
        else yy++;
    }

    // for (long long i=n;i>=1;i--) {
    //     for (long long j=1;j<=n;j++) std::cout<<(long long)mapp[j][i].size()<<" ";
    //     std::cout<<std::endl;
    // }

    for (long long i=n;i>=1;i--) { //yy
        for (long long j=1;j<=n;j++) {
            // mapp[j][i].push_back(m);
            for (long long l=1;l<(long long)mapp[j][i].size();l++) {
                long long len=mapp[j][i][l]-mapp[j][i][l-1]-1;
                ans[j][i]+=(len+1)*(len)/2;
            }
            long long ls=(long long)mapp[j][i].size();
            if (ls) {
                ans[j][i]+=(mapp[j][i][0])*(mapp[j][i][0]-1)/2;
                ans[j][i]+=(m-mapp[j][i][ls-1]+1)*(m-mapp[j][i][ls-1])/2;
            }
            else ans[j][i]+=m*(m+1)/2;

            std::cout<<ans[j][i]<<" ";
        }
        std::cout<<std::endl;
    }
 
    return 0;
}
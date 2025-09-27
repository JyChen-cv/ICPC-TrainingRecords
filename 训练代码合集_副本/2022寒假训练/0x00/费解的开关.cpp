#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

long long mapp[6][6],f[6][6];

void deal1(long long x,long long y) 
{
    // std::cout<<x<<" ??? "<<y<<std::endl;
    // if (mapp[x][y]==1) mapp[x][y]=0;
    // else mapp[x][y]=1;
    // if (mapp[x-1][y]==1) mapp[x-1][y]=0;
    // else mapp[x-1][y]=1;
    // if (mapp[x][y-1]==1) mapp[x][y-1]=0;
    // else mapp[x][y-1]=1;
    // if (mapp[x+1][y]==1) mapp[x+1][y]=0;
    // else mapp[x+1][y]=1;
    // if (mapp[x][y+1]==1) mapp[x][y+1]=0;
    // else mapp[x][y+1]=1;
    mapp[x][y]^=1;
    mapp[x-1][y]^=1;
    mapp[x][y-1]^=1;
    mapp[x+1][y]^=1;
    mapp[x][y+1]^=1;
}

bool deal(long long & x)
{
    for (long long i=1;i<=5;i++) {
        for (long long j=1;j<=5;j++) {
            if (mapp[i][j]!=1) {
                deal1(i+1,j);
                x--;
                if (x<0) return 0;
            }
        }
    }
    return 1;
}

long long main()
{
    freopen("okok.in","r",stdin);

    long long t;
    std::cin>>t;
    while (t--) {
        long long ans=0x3f3f3f;

        for (long long i=1;i<=5;i++) {
            for (long long j=1;j<=5;j++) {
                std::cin>>f[i][j];
            }
        }

        for (long long i=0;i<=31;i++) {
            for (long long ii=0;ii<=5;ii++) {
                for (long long jj=0;jj<=5;jj++) {
                    mapp[ii][jj]=f[ii][jj];
                }
            }

            for (long long ii=0;ii<=5;ii++) {
                for (long long jj=0;jj<=5;jj++) {
                    std::cout<<f[ii][jj]<<" ";
                }
                std::cout<<std::endl;
            }
            
            long long all=6,val=i;
            for (long long j=0;j<5;j++) {
                if (val>=(1<<j)) {
                    val-=(1<<j);
                    all--;
                    deal1(1,j+1);
                }
                if (val==0) break;
            }
            
            // for (long long ii=0;ii<=5;ii++) {
            //     for (long long jj=0;jj<=5;jj++) {
            //         std::cout<<mapp[ii][jj]<<" ";
            //     }
            //     std::cout<<std::endl;
            // }

            long long tag=deal(all);
            if (tag==1) ans=std::min(ans,all);
            std::cout<<all<<" "<<i<<std::endl;
        }
        if (ans==0x3f3f3f) std::cout<<"-1"<<std::endl;
        else std::cout<<ans<<std::endl;
    }

    return 0;
}

// 莫名其妙的问题，f，莫名其妙就改变了
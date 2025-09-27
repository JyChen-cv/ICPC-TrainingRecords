#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100;
long long mapp[N+2][N+2],s[N+2][N+2];
long long dx,dy;

long long dis(long long x1,long long y1,long long x2,long long y2)
{
    return std::abs(x1-x2)+std::abs(y1-y2);
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset (mapp,0,sizeof(mapp));
        dx=0;
        dy=0;

        long long n,m;
        std::cin>>n>>m;
        for (long long i=1;i<=m;i++) {  // 先循环竖着的
            for (long long j=1;j<=n;j++) {
                std::cin>>mapp[i][j];
                dx+=i*mapp[i][j];
                dy+=j*mapp[i][j];
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mapp[i][j];
            }
        }
        dx/=s[m][n];
        dy/=s[m][n];
        
        long long ans=0x3f3f3f3f,ans1=0;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        ans1=0;
        dx++;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        ans1=0;
        dy++;
        dx--;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);
        
        ans1=0;
        dx++;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        //?????????????????????????????????????????????????????????????????
        dx--;
        dy--;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        ans1=0;
        dx--;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        ans1=0;
        dy--;
        dx++;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);
        
        ans1=0;
        dx--;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        dx++;
        dy++;
        //???????????????????????????????????????????????????????????????

        dx++;
        dy--;
        ans1=0;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);

        dx-=2;
        dy+=2;
        ans1=0;
        for (long long i=1;i<=m;i++) {
            for (long long j=1;j<=n;j++) {
                ans1+=dis(i,j,dx,dy)*mapp[i][j];
                // std::cout<<ans<<" ";
            }
            // std::cout<<std::endl;
        }
        ans=std::min(ans,ans1);
        std::cout<<ans<<std::endl;
    }

    return 0;
}
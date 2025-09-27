#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>

const int N=2e5;
int fa[N+2][20],dep[N+2];
struct group {
    int lmax,rmax,amax;
    int lmin,rmin,amin;
    int sum;
} dp[N+2][20];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n,num=1;
        std::cin>>n;
        for (int i=1;i<=n;i++) {
            for (int j=0;j<20;j++) {
                fa[i][j]=0;
                dp[i][j].lmax=dp[i][j].lmin=dp[i][j].rmax=dp[i][j].rmin=dp[i][j].amax=dp[i][j].amin=dp[i][j].sum=0;
            }
        }
        for (int i=0;i<20;i++) dp[1][i].lmax=dp[1][i].rmax=dp[1][i].amax=dp[1][i].sum=1;
        dep[1]=1;

        for (int k=1;k<=n;k++) {
            char ch;
            std::cin>>ch;
            if (ch=='+') {
                int a,b;
                std::cin>>a>>b;
                num++;
                dep[num]=dep[a]+1;
                fa[num][0]=a;
                dp[num][0].lmax=std::max(0,b);
                dp[num][0].rmax=std::max(0,b);
                dp[num][0].amax=std::max(0,b);
                dp[num][0].lmin=std::min(0,b);
                dp[num][0].rmin=std::min(0,b);
                dp[num][0].amin=std::min(0,b);
                dp[num][0].sum=b;
                
                for (int j=1;j<20;j++) {
                    fa[num][j]=fa[fa[num][j-1]][j-1];
                    dp[num][j].sum=dp[fa[num][j-1]][j-1].sum+dp[num][j-1].sum;
                    dp[num][j].lmax=std::max(dp[fa[num][j-1]][j-1].lmax,dp[fa[num][j-1]][j-1].sum+dp[num][j-1].lmax);
                    dp[num][j].rmax=std::max(dp[num][j-1].rmax,dp[num][j-1].sum+dp[fa[num][j-1]][j-1].rmax);
                    dp[num][j].amax=std::max(std::max(dp[num][j-1].amax,dp[fa[num][j-1]][j-1].amax),dp[num][j-1].lmax+dp[fa[num][j-1]][j-1].rmax);
                    dp[num][j].lmin=std::min(dp[fa[num][j-1]][j-1].lmin,dp[fa[num][j-1]][j-1].sum+dp[num][j-1].lmin);
                    dp[num][j].rmin=std::min(dp[num][j-1].rmin,dp[num][j-1].sum+dp[fa[num][j-1]][j-1].rmin);
                    dp[num][j].amin=std::min(std::min(dp[num][j-1].amin,dp[fa[num][j-1]][j-1].amin),dp[num][j-1].lmin+dp[fa[num][j-1]][j-1].rmin);
                }
            }
            else {
                int a,b,c;
                std::cin>>a>>b>>c;
                int almax=0,armax=0,almin=0,armin=0,aamax=0,aamin=0,asum=0;
                int blmax=0,brmax=0,blmin=0,brmin=0,bamax=0,bamin=0,bsum=0;
                if (dep[a]<dep[b]) std::swap(a,b);
                for (int i=19;i>=0;i--) {
                    if (dep[fa[a][i]]>=dep[b]) {
                        aamax=std::max(std::max(aamax,dp[a][i].amax),almax+dp[a][i].rmax);
                        aamin=std::min(std::min(aamin,dp[a][i].amin),almin+dp[a][i].rmin);
                        almax=std::max(almax+dp[a][i].sum,dp[a][i].lmax);
                        almin=std::min(almin+dp[a][i].sum,dp[a][i].lmin);
                        armax=std::max(armax,asum+dp[a][i].rmax);
                        armin=std::min(armin,asum+dp[a][i].rmin);
                        asum+=dp[a][i].sum;
                        a=fa[a][i];
                    }
                }
                if (a==b) {
                    aamax=std::max(std::max(aamax,dp[a][0].amax),almax+dp[a][0].rmax);
                    aamin=std::min(std::min(aamin,dp[a][0].amin),almin+dp[a][0].rmin);
                    almax=std::max(almax+dp[a][0].sum,dp[a][0].lmax);
                    almin=std::min(almin+dp[a][0].sum,dp[a][0].lmin);
                    armax=std::max(armax,asum+dp[a][0].rmax);
                    armin=std::min(armin,asum+dp[a][0].rmin);
                    asum+=dp[a][0].sum;
                    // std::cout<<dp[a][0].rmax<<" "<<almax<<std::endl;
                    // a=fa[a][0];
                    if (c<=aamax && c>=aamin) std::cout<<"YES"<<std::endl;
                    else std::cout<<"NO"<<std::endl;
                    continue;
                }
                for (int i=19;i>=0;i--) {
                    if (fa[a][i]!=fa[b][i]) {
                        aamax=std::max(std::max(aamax,dp[a][i].amax),almax+dp[a][i].rmax);
                        aamin=std::min(std::min(aamin,dp[a][i].amin),almin+dp[a][i].rmin);
                        almax=std::max(almax+dp[a][i].sum,dp[a][i].lmax);
                        almin=std::min(almin+dp[a][i].sum,dp[a][i].lmin);
                        armax=std::max(armax,asum+dp[a][i].rmax);
                        armin=std::min(armin,asum+dp[a][i].rmin);
                        asum+=dp[a][i].sum;
                        a=fa[a][i];
                        bamax=std::max(std::max(bamax,dp[b][i].amax),blmax+dp[b][i].rmax);
                        bamin=std::min(std::min(bamin,dp[b][i].amin),blmin+dp[b][i].rmin);
                        blmax=std::max(blmax+dp[b][i].sum,dp[b][i].lmax);
                        blmin=std::min(blmin+dp[b][i].sum,dp[b][i].lmin);
                        brmax=std::max(brmax,bsum+dp[b][i].rmax);
                        brmin=std::min(brmin,bsum+dp[b][i].rmin);
                        bsum+=dp[b][i].sum;
                        b=fa[b][i];
                    }
                }
                aamax=std::max(std::max(aamax,dp[a][1].amax),almax+dp[a][1].rmax);
                aamin=std::min(std::min(aamin,dp[a][1].amin),almin+dp[a][1].rmin);
                almax=std::max(almax+dp[a][1].sum,dp[a][1].lmax);
                almin=std::min(almin+dp[a][1].sum,dp[a][1].lmin);
                armax=std::max(armax,asum+dp[a][1].rmax);
                armin=std::min(armin,asum+dp[a][1].rmin);
                asum+=dp[a][1].sum;
                a=fa[a][1];
                bamax=std::max(std::max(bamax,dp[b][0].amax),blmax+dp[b][0].rmax);
                bamin=std::min(std::min(bamin,dp[b][0].amin),blmin+dp[b][0].rmin);
                blmax=std::max(blmax+dp[b][0].sum,dp[b][0].lmax);
                blmin=std::min(blmin+dp[b][0].sum,dp[b][0].lmin);
                brmax=std::max(brmax,bsum+dp[b][0].rmax);
                brmin=std::min(brmin,bsum+dp[b][0].rmin);
                bsum+=dp[b][0].sum;
                // b=fa[b][i];
                int mm=std::max(std::max(aamax,bamax),almax+blmax);
                int nn=std::min(std::min(aamin,bamin),almin+blmin);
                if (c<=mm && c>=nn) std::cout<<"YES"<<std::endl;
                else std::cout<<"NO"<<std::endl;
            }
        }
    }
    return 0;
}
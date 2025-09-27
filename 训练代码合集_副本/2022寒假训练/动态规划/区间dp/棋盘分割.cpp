#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=20,M=9;
double s[M][M],f[M][M][M][M][N],mapp[M][M],x;
long long m;

double get(long long x1,long long y1,long long x2,long long y2) 
{
    double sum=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]-x;
    return sum*sum/m;
}

double dp(long long x1,long long y1,long long x2,long long y2,long long k) //k表示还要分成几部分
{
    double &v=f[x1][y1][x2][y2][k];
    if (v>=0) return v;   // 前面赋值为负数更加保险
    if (k==1) return v=get(x1,y1,x2,y2);

    v=1e9;
    for (long long i=x1;i<x2;i++) {
        v=std::min(v,dp(x1,y1,i,y2,k-1)+get(i+1,y1,x2,y2));
        v=std::min(v,dp(i+1,y1,x2,y2,k-1)+get(x1,y1,i,y2));
    }
    for (long long i=y1;i<y2;i++) {
        v=std::min(v,dp(x1,y1,x2,i,k-1)+get(x1,i+1,x2,y2));
        v=std::min(v,dp(x1,i+1,x2,y2,k-1)+get(x1,y1,x2,i));
    }

    return v;
}

long long main()
{
    std::cin>>m;
    for (long long i=1;i<=8;i++) {
        for (long long j=1;j<=8;j++) {
            std::cin>>mapp[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+mapp[i][j];
        }
    }

    memset (f,-1,sizeof(f));
    x=s[8][8]/m;
    prlong longf("%.3lf\n",std::sqrt(dp(1,1,8,8,m)));

    return 0;
}
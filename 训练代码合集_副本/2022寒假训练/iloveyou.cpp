#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=684594;
std::string mapp;
long long f[N+2][10];
const long long mod=20010905;
char lev[9]={0,'i','l','o','v','e','y','o','u'};

long long main()
{
    std::cin>>mapp;
    for (long long i=0;i<(long long)mapp.size();i++) {
        if (mapp[i]<='Z' && mapp[i]>='A') mapp[i]+='a'-'A';
    } // 大小写转为小写
    
    // f[j][i] 表示，后j个字符中，后i个字符出现的次数
    for (long long i=0;i<=(long long)mapp.size();i++) f[i][9]=1;
    for (long long i=8;i>=1;i--) {
        for (long long j=(long long)mapp.size()-1;j>=0;j--) {
            f[j][i]=f[j+1][i];
            if (mapp[j]==lev[i]) {
                f[j][i]+=f[j][i+1];
                f[j][i]%=mod;
            }
        }
    }

    std::cout<<f[0][1]<<std::endl;

    return 0;
}
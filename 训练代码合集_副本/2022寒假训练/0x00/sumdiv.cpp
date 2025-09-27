#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long mod=9901;
bool mapp[10000];
long long num[10000];

long long qm(long long x,long long y) 
{
    if (y==0) return 1;
    if (y%2==1) {
        long long ls=qm(x,(y-1)/2);
        return ls*ls%mod*x%mod;
    }
    else {
        long long ls=qm(x,y/2);
        return ls*ls%mod;
    }
}

long long deal(long long x,long long y)
{
    if (y==0) return 1;
    if (y%2==1) {
        long long ls=deal(x,(y-1)/2);
        return (1+qm(x,(y+1)/2))%mod*ls%mod;
    }
    else {
        long long ls=deal(x,y/2-1);
        return ((1+qm(x,y/2))%mod*ls%mod+qm(x,y))%mod;
    }
}

long long main()
{
    long long a,b;
    std::cin>>a>>b;
    if (a==0) {
        std::cout<<0<<std::endl;
        return 0;
    }
    if (b==0) {
        std::cout<<1<<std::endl;
        return 0;
    }
    mapp[1]=1;
    for (long long i=2;i<=10000;i++) {
        if (mapp[i]==0) 
            for (long long j=2;j*i<=10000;j++) {
                mapp[j*i]=1;
            }
        // if (mapp[i]==0) std::cout<<i<<" ";
    }

    long long val=a; 
    for (long long i=1;i<=10000;i++) {
        if (mapp[i]==0)
            while (val%i==0) {
                val/=i;
                num[i]++;
            }
        // if (num[i]) std::cout<<i<<" "<<num[i]<<std::endl;
    }

    long long ans=1;
    for (long long i=1;i<=10000;i++) {
        num[i]*=b;
        if (num[i]) {
            ans*=deal(i,num[i]);
            ans%=mod;
            // std::cout<<ans<<std::endl;
        }
    } 
    if (val!=1) {
        val%=mod;   // 找到了，罪魁祸首！！！！！！！！！！！！！！！！！！！！！
        ans*=deal(val,b);
        ans%=mod;
    }

    std::cout<<ans<<std::endl;
    return 0;
}
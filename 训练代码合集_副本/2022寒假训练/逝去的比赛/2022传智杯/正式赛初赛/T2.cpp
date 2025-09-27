#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>

const long long N=2*1e5;
long long mapp[N+6],mapp2[N+6];
long long ans1[N+6],ans2[N+6];

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }
    for (long long i=1;i<=n;i++) {
        ans1[i]=mapp[n+1-i];
    }
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp2[i];
    }
    for (long long i=1;i<=m;i++) {
        ans2[i]=mapp2[m+1-i];
    }
    if (n<m) {
        std::swap(n,m);
        std::swap(ans1,ans2);
    }
    // for (long long i=1;i<=m;i++) std::cout<<ans2[i]<<" ";
    // std::cout<<std::endl;

    long long ls=0;
    for (long long i=1;i<=n;i++) {
        long long lls=ans1[i]+ans2[i]+ls;
        if (lls>i) {
            ans1[i]=lls-(i+1);
            ls=1;
        }
        else {
            ans1[i]=lls;
            ls=0;
        }
    }
    if (ls) std::cout<<ls<<" ";
    for (long long i=n;i>=1;i--) std::cout<<ans1[i]<<" ";

    return 0;
}
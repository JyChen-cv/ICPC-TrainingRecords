#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>

const long long N=20;
std::string mapp[N+2];
long long n;

bool cmp(std::string a,std::string b) {  // 永远是a，b来比较，来确定返回值到底是1还是0，而不能颠倒为b和a来确定返回值
    long long len1=a.size();
    long long len2=b.size();
    if (len1<=len2) {
        for (long long i=0;i<len1;i++) {
            if (b[i]>a[i]) return 0;
            else if (b[i]<a[i]) return 1;
        }
        return 0;
    }
    else {
        for (long long i=0;i<len1;i++) {
            if (b[i]>a[i]) return 0;
            else if (b[i]<a[i]) return 1;
        }
        return 1;
    }
}


long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i];
    }

    std::sort(mapp+1,mapp+n+1,cmp);

    for (long long i=1;i<=n;i++) std::cout<<mapp[i];

    return 0;
}
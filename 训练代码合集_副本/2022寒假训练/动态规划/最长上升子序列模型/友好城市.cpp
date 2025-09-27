#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

const long long MaxN=5000;
struct group {
    long long num1;
    long long num2;
} mapp[MaxN+2];
long long f[MaxN+2];

bool cmp(group x,group y) {
    return x.num1<y.num1;
}

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>mapp[i].num1>>mapp[i].num2;
    }
    std::sort(mapp+1,mapp+1+n,cmp);

    long long ans=0;
    for (long long i=1;i<=n;i++) {
        f[i]=1;
        for (long long j=1;j<i;j++) {
            if (mapp[i].num2>mapp[j].num2) f[i]=std::max(f[i],f[j]+1);
        }
        ans=std::max(ans,f[i]);
    }

    std::cout<<ans<<std::endl;
    return 0;
}
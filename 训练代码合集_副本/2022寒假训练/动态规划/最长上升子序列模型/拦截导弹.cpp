#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>

const long long MaxN=1000;
long long mapp[MaxN+2],f[MaxN+2];

long long main()
{
    long long n=1,ans1=0;
    while (std::cin>>mapp[n]) n++;
    n--;

    for (long long i=1;i<=n;i++) {
        f[i]=1;
        for (long long j=1;j<i;j++) {
            if (mapp[j]>=mapp[i]) f[i]=std::max(f[i],f[j]+1);
        }
        ans1=std::max(ans1,f[i]);
    }

    memset(f,0,sizeof(f));
    long long len=0;
    for (long long i=1;i<=n;i++) {
        long long x=std::lower_bound(f+1,f+len+1,mapp[i])-f;  //注意这里一定不能写成n，一定是len，因为lower_bound的本质是二分查找！！！
        if (x>len) {
            len++;
            f[len]=mapp[i];
        }
        else f[x]=mapp[i];
        // std::cout<<len<<" "<<i<<" "<<x<<" "<<f[len]<<" "<<mapp[i]<<std::endl;
    }
    std::cout<<ans1<<std::endl;
    std::cout<<len<<std::endl;
    return 0;
}
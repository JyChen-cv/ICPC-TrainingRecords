#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

const long long N=1000000;
long long mapp[N+2];

long long main()
{
    long long n,k;
    std::cin>>n;
    for (long long i=1;i<=n;i++) scanf("%d",&mapp[i]);
    std::cin>>k;
    std::sort(mapp+1,mapp+n+1);
    long long lls=std::lower_bound(mapp+1,mapp+n+1,k)-(mapp+1);
    k=mapp[lls];
    long long ls=0;
    long long ans=0;
    for (long long i=1;i<=n;i++) {
        if (ls+mapp[i]<=k) {
            ls+=mapp[i];
            ans++;
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}
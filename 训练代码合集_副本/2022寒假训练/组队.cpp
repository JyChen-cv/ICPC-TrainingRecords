// md傻逼你tm写题前先用蹄子算算样例，md连个题目都看不清

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

const long long N=200000;
long long mapp[N+2];

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long tag1=1,tag2=1;
        long long n,m;
        scanf("%d%d",&n,&m);
        for (long long i=1;i<=n;i++) {
            scanf("%d",&mapp[i]);
        }
        std::sort(mapp+1,mapp+n+1);

        long long ans=0;
        for ( ; ; ) {
            if (mapp[tag2]-mapp[tag1]<=m) {
                ans=std::max(ans,tag2-tag1+1);
                tag2++;
            }
            else tag1++;
            
            if (tag2>=n) break;
        }
        prlong longf("%d\n",ans);
    }

    return 0;
}
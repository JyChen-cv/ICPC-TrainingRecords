#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>

const long long N=1e5;
long long mapp[N+2],mappp[N+2],map_num[N+2],map_num2[N+2];
long long n,m,nn;

bool cck(long long x,long long y)
{  
    long long tx=x;
    long long ty=y;
    long long ans=0;
    if (map_num[tx-1]>map_num2[ty+1]) {
        ans+=map_num2[ty+1]*2+map_num[tx-1];
    }
    else ans+=map_num2[ty+1]+map_num[tx-1]*2;
    return ans<=m;
}

bool check(long long x)
{
    long long tag1=0,tag2=0;
    while (tag2<=n) {
        if (mappp[tag2+1]-mappp[tag1]<=x) {
            if (cck(tag1,tag2+1)) return 1;
            tag2++;
        }
        else tag1++;
    }
    return 0;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        scanf("%lld",&mapp[i]);
    }
    std::sort(mapp+1,mapp+n+1);
    for (long long i=1;i<=n;i++) {
        map_num[i]++;
        if(mapp[i]!=mapp[i-1]) {
            mappp[++nn]=mapp[i];
        }
        else {
            map_num[nn]++;
        }
    }

    for (long long i=nn;i>=1;i--) {
        map_num2[i]=map_num[i];
        map_num2[i]+=map_num2[i+1];
    }
    for (long long i=1;i<=nn;i++) {
        map_num[i]+=map_num[i-1];
    }

    long long l=0,r=1e10; 
    while (l<r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    std::cout<<l<<std::endl;

    return 0;
}
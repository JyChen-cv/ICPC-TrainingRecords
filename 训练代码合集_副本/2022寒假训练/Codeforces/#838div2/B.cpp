#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

const long long N=50000;
std::pair<long long,long long> mapp[N+2];
long long ans[N+2],cnt;
std::vector<std::pair<long long,long long> > l;


void deal(long long x,long long y)
{
    long long ls=ans[x];
    while (ls>y) {
        l.push_back(std::make_pair(x,y));
        y*=2;
        ls-=y;
        cnt++;
    }
    if (ls) {
        l.push_back(std::make_pair(x,ls));
        cnt++;
    }
}

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        memset(ans,0,sizeof(ans));
        memset(mapp,0,sizeof(mapp));
        l.clear();

        long long n;
        std::cin>>n;
        for (long long i=1;i<=n;i++) {
            long long a;
            std::cin>>a;
            mapp[i]=std::make_pair(a,i);
        }
        std::sort(mapp+1,mapp+n+1);
        cnt=0;
        for (long long i=2;i<=n;i++) {
            if (mapp[i-1].first==mapp[i].first) continue;
            long long j=0,k=1000000000;
            while (j<k) {
                long long mid=(j+k)/2;
                if (mapp[i-1].first*mid>=mapp[i].first) {
                    k=mid;
                }
                else j=mid+1;
            }
            ans[mapp[i].second]=mapp[i-1].first*j-mapp[i].first;
            if (ans[mapp[i].second]) {
                deal(mapp[i].second,mapp[i].first);
            }
            mapp[i].first=mapp[i-1].first*j;
        }
        std::cout<<cnt<<std::endl;
        for (long long i=0;i<(long long)l.size();i++) {
            std::cout<<l[i].first<<" "<<l[i].second<<std::endl;
        }
    }
    return 0;
}
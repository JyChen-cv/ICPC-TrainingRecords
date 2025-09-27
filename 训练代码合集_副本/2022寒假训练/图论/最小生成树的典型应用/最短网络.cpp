#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=100;
struct group {
    long long x,y,z;
    bool operator < (const group &t)const {
        return z<t.z;
    }
};
std::vector<group> mapp;
long long n,fa[N+2];

long long find(long long x) {
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        fa[i]=i;
        for (long long j=1;j<=n;j++) {
            long long c;
            std::cin>>c;
            if (j>i) mapp.push_back({i,j,c});
        }
    }
    std::sort(mapp.begin(),mapp.end());
    long long ans=0;
    for (long long i=0;i<(long long)mapp.size();i++) {
        long long a=find(mapp[i].x),b=find(mapp[i].y);
        if (a!=b) {
            ans+=mapp[i].z;
            fa[b]=a;
        }
    }
    std::cout<<ans<<std::endl;

    return 0;
}
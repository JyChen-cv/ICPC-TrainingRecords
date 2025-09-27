#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

const long long N=300;
struct group {
    long long x,y,z;
    bool operator < (const group &t)const {
        return z<t.z;
    }
};
std::vector<group> mapp;
long long node[N+2],n,fa[N+2],ans;

long long find(long long x) 
{
    if (fa[x]==x) {
        return x;
    }
    else {
        return fa[x]=find(fa[x]);
    } 
}

long long main()
{
    std::cin>>n;
    for (long long i=1;i<=n;i++) {
        std::cin>>node[i];
        fa[i]=i;
        ans+=node[i];
    }
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            long long a;
            std::cin>>a;
            if (j>i) mapp.push_back({i,j,a});
        }
    }
    std::sort(mapp.begin(),mapp.end());

    for (long long i=0;i<(long long)mapp.size();i++) {
        long long a=find(mapp[i].x),b=find(mapp[i].y),c=mapp[i].z;
        if (a==b) continue;
        else {
            if (node[a]>=node[b]) {
                if (node[a]>c) {
                    fa[a]=b;
                    ans+=c;
                    ans-=node[a];
                }
            }
            else {
                if (node[b]>c) {
                    fa[b]=a;
                    ans+=c;
                    ans-=node[b];
                }
            }
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}
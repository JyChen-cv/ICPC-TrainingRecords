#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

const long long N=500;
std::pair<double,double> mapp[N+2];
struct group {
    long long x,y;
    double z;
    bool operator < (const group &t)const {
        return z<t.z;
    }
};
std::vector<group> s;
std::vector<double> ans;
long long fa[N*N+2];

double deal(long long x,long long y) {
    double aa=mapp[x].first-mapp[y].first,bb=mapp[x].second-mapp[y].second;
    return std::sqrt((aa)*(aa)+(bb)*(bb));
}

long long find(long long x) {
    if (fa[x]==x) return x;
    else return find(fa[x]);
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        double a,b;
        std::cin>>a>>b;
        mapp[i]=std::make_pair(a,b);
    }
    for (long long i=1;i<=n;i++) {
        for (long long j=i+1;j<=n;j++) {
            s.push_back((group){i,j,deal(i,j)});
        }
    }
    std::sort(s.begin(),s.end());
    for (long long i=0;i<=n;i++) fa[i]=i;
    for (long long i=0;i<(long long)s.size();i++) {
        long long a=find(s[i].x),b=find(s[i].y);
        if (a==b) continue;
        else {
            fa[a]=b;
            ans.push_back(s[i].z);
        }
    }
    std::sort(ans.begin(),ans.end());
    prlong longf("%.2lf\n",ans[(long long)ans.size()-std::max(m,1)]);
    return 0;
}
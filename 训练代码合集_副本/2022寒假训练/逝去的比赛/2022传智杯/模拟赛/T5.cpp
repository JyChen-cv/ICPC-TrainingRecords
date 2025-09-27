#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>

const long long N=100000;
long long fa[N+2],v[N+2],aa[N+2],bb[N+2],cc[N+2],tag[N+2];
std::pair<long long,long long> edge[N+2];
std::stack<long long> ans;

long long find (long long x)
{
    if (fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) {
        std::cin>>v[i];
    }
    for (long long i=1;i<n;i++) {
        long long a,b;
        std::cin>>a>>b;
        edge[i].first=a;
        edge[i].second=b;
    }
    for (long long i=1;i<=m;i++) {
        std::cin>>aa[i];
        if (aa[i]==1) {
            std::cin>>bb[i];
            tag[bb[i]]=1;
        }
        if (aa[i]==2) {
            std::cin>>bb[i]>>cc[i];
            // std::swap(v[bb[i]],cc[i]);
            long long ls=v[bb[i]]-cc[i];
            v[bb[i]]=cc[i];
            cc[i]=ls;  // 这里写的稍有点迷惑，本来是想直接更改操作变成反向来存的，后来发现不太对，反正最后要维护总和，那不如就直接存一下差值就结束啦
        }
        if (aa[i]==3) std::cin>>bb[i];
    }

    for (long long i=1;i<=n;i++) fa[i]=i;
    for (long long i=1;i<n;i++) {
        if (tag[i]==1) continue;
        if (v[edge[i].first]>v[edge[i].second]) std::swap(edge[i].first,edge[i].second);
        v[find(edge[i].second)]+=v[find(edge[i].first)];
        fa[find(edge[i].first)]=find(edge[i].second);
    }
    for (long long j=m;j>=1;j--) {
        if (aa[j]==3) {
            // std::cout<<v[find(bb[j])]<<std::endl;
            ans.push(v[find(bb[j])]);
        }
        else if (aa[j]==2) {
            v[find(bb[j])]+=cc[j];
        }
        else {
            long long i=bb[j];
            if (v[edge[i].first]>v[edge[i].second]) std::swap(edge[i].first,edge[i].second);
            v[find(edge[i].second)]+=v[find(edge[i].first)];
            fa[find(edge[i].first)]=find(edge[i].second);
        }
    }
    while (ans.size()) {
        std::cout<<ans.top()<<std::endl;
        ans.pop();
    }
    return 0;
}
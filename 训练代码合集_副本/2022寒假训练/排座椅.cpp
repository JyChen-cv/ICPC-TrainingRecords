#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

const long long N=1000;
struct group {
    long long num;
    long long val;
} heng[N+2],shu[N+2];
long long n,m,nheng,nshu,all;
std::vector<long long> ans;

bool cmp(group x,group y)
{
    return x.val>y.val;
}

long long main()
{
    std::cin>>m>>n>>nheng>>nshu>>all;
    for (long long i=1;i<=n;i++) shu[i].num=i;
    for (long long i=1;i<=m;i++) heng[i].num=i;
    for (long long i=1;i<=all;i++) {
        long long a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if (a==c) {
            if (b>d) shu[d].val++;
            else shu[b].val++;
        }
        else {
            if (a>c) heng[c].val++;
            else heng[a].val++;
        }
    }
    std::sort(heng+1,heng+m+1,cmp);
    std::sort(shu+1,shu+n+1,cmp);
    
    for (long long i=1;i<=nheng;i++) ans.push_back(heng[i].num);
    std::sort(ans.begin(),ans.end());
    for (long long i=0;i<(long long)ans.size();i++) std::cout<<ans[i]<<" ";
    std::cout<<std::endl;
    ans.clear();
    for (long long i=1;i<=nshu;i++) ans.push_back(shu[i].num);
    std::sort(ans.begin(),ans.end());
    for (long long i=0;i<(long long)ans.size();i++) std::cout<<ans[i]<<" ";
    return 0;
}
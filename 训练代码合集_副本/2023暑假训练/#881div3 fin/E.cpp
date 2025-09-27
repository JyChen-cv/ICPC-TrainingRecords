#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

const int N=100000;
int s[N+2],n,m,mapp[N+2],sam[N+2];
std::vector<std::pair<int,int> > p;

bool check(int x) {
    for (int i=1;i<=n;i++) {
        mapp[i]=0;
        sam[i]=0;
    }
    for (int i=1;i<=x;i++) {
        mapp[s[i]]=1;
    }
    for (int i=1;i<=n;i++) {
        sam[i]=sam[i-1]+mapp[i];
    }
    // for (int i=1;i<=n;i++) std::cout<<mapp[i]<<" ";
    // std::cout<<std::endl;
    for (int i=0;i<m;i++) {
        // std::cout<<i<<std::endl;
        if ((p[i].second-p[i].first+1+2)/2<=sam[p[i].second]-sam[p[i].first-1]) return 1;
    }
    return 0;
}

int main() 
{
    int t;
    std::cin>>t;
    while (t--) {
        p.clear();

        std::cin>>n>>m;
        for (int i=1;i<=m;i++) {
            int a,b;
            std::cin>>a>>b;
            p.push_back(std::make_pair(a,b));
        }
        int q;
        std::cin>>q;
        for (int i=1;i<=q;i++) {
            std::cin>>s[i];
        }

        int l=1,r=q+1;
        while (l<r) {
            // std::cout<<l<<" "<<r<<std::endl;
            int mid=(l+r)/2;
            if (!check(mid)) {
                l=mid+1;
            }
            else r=mid;
        }
        if (r==(q+1)) std::cout<<-1<<std::endl;
        else std::cout<<r<<std::endl;
    }
}
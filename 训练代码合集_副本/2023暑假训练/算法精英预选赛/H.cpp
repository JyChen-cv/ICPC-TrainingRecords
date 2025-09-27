#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

#define x first 
#define y second
const int N=1e6;
int n;
std::pair<long long,long long> mapp[N+2];

bool check(long long mid)
{
    long long tag=mid;
    for (int i=1;i<=n;i++) {
        if (mapp[i].x>=mid) {
            tag-=mapp[i].y;
            if (tag<=0) return true;
        }
        else {
            tag=mid;
        }
    }
    return false;
}

int main()
{
    std::cin>>n;
    for (int i=1;i<=n;i++) {
        scanf("lldlld",&mapp[i].x,&mapp[i].y);
    }
    long long l=0,r=1e9;
    while (l<r) {
        int mid=(l+r)>>1;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    std::cout<<(r*r)<<std::endl;
    return 0;
}
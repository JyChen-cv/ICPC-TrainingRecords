#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

const int N=1000;
int mapp[N+2];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n;
        std::cin>>n;
        for (int i=1;i<=n;i++) {
            std::cin>>mapp[i];
        }
        std::sort(mapp+1,mapp+n+1);
        int ans=0;
        for (int i=1;i<=n/2;i++) {
            ans+=(mapp[n+1-i]-mapp[i]);
        }
        std::cout<<ans<<std::endl;
    }
    return 0;
}
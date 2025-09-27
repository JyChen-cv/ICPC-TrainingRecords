#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>

const int N=2e5;
long long mapp[N+2];

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n;
        std::cin>>n;
        long long ans=0;
        int cnt_p=0;
        int cnt_n=0;
        mapp[0]=1;
        for (int i=1;i<=n;i++) {
            std::cin>>mapp[i];
            if (mapp[i]==0) {
                i--;
                n--;
                continue;
            }
            ans+=std::abs(mapp[i]);
            if (mapp[i]*mapp[i-1]<0) {
                if (mapp[i]>0) cnt_p++;
                else cnt_n++;
            }
        }
        std::cout<<ans<<" ";
        if (cnt_p>=cnt_n) std::cout<<cnt_n<<std::endl;
        else std::cout<<(cnt_p+1)<<std::endl;
    }
    return 0;
}
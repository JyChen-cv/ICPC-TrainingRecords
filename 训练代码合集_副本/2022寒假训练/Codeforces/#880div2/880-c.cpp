#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

const long long p_p[8]={0,10,100,1000,10000,100000,1000000,10000000};

int main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        long long a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if (c<std::max(a,b) || c-std::max(a,b)>(long long)1) {
            std::cout<<"-1"<<std::endl;
            continue;
        }
        long long cnt=0;
        long long tag=0;
        for (long long i=0;i<(p_p[a]-p_p[a-1]);i++) {
            if (a==1 && i==0) continue;
            long long cnt1=std::max(std::max(p_p[b-1],p_p[c-1]-p_p[a-1]-i),(long long)1);
            long long cnt2=std::min(p_p[c]-1-p_p[a-1]-i,p_p[b]-(long long)1);
            // std::cout<<i<<" "<<cnt1<<" "<<cnt2<<std::endl;
            if (cnt1>cnt2) continue;
            if (d>cnt+(cnt2-cnt1+1)) {
                cnt+=(cnt2-cnt1+1);
            }
            else {
                d-=cnt;
                std::cout<<(p_p[a-1]+i)<<" + "<<(cnt1+d-1)<<" = "<<((p_p[a-1]+i)+(cnt1+d)-1)<<std::endl;
                tag=1;
                break;
            }
        }
        if (tag==0) std::cout<<(-1)<<std::endl;
    }
    return 0;
}

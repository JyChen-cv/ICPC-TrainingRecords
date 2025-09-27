#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const long long N=100000;
long long BIT[N+2],mapp[N+2];
long long n;

inline long long lowbit(long long x)
{
    return x&(-x);
}

void update(long long x)
{
    for (long long i=x;i<=n;i+=lowbit(i)) {
        BIT[i]-=1;
    }
}

long long sum(long long x)
{
    long long ans=0;
    for (long long i=x;i;i-=lowbit(i)) {
        ans+=BIT[i];
    }
    return ans;
}

long long main()
{
    std::cin>>n;
    mapp[1]=0;
    BIT[1]=1;
    for (long long i=2;i<=n;i++) {
        std::cin>>mapp[i];
        BIT[i]=lowbit(i);
    }
    
    for (long long i=n;i>=1;i--) {
        long long l=1,r=n;
        while (l<r) {
            long long mid=(l+r)>>1;
            if (sum(mid)>=mapp[i]+1) {
                r=mid;
            }
            else l=mid+1;  // 这里二分的写法还是要注意的，一般都是左面的这里写+1，因为是向零取整，还有就是注意去等的位置一定是包含想要的结果的那个位置
        }
        mapp[i]=r;
        update(r);
    }
    for (long long i=1;i<=n;i++) std::cout<<mapp[i]<<std::endl;

    return 0;
}
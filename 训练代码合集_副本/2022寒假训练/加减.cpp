#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <queue>
#include <vector>

const long long N=100000;
long long mapp[N+2],m,s[N+2];
long long n;

bool check (long long x)
{
    for (long long i=1;i+x-1<=n;i++) {
        long long j=i+x-1;
        long long mid=(i+j)/2;
        if ((s[j]-s[mid]-mapp[mid]*(j-mid))+(mapp[mid]*(mid-i+1)-s[mid]+s[i-1])<=m) return 1;
    }
    return 0;
}

long long main()
{
    std::cin>>n>>m;
    for (long long i=1;i<=n;i++) std::cin>>mapp[i];
    std::sort(mapp+1,mapp+n+1);  // 这样相同数字出现一定是连续的一段
    for (long long i=1;i<=n;i++) {
        s[i]=s[i-1]+mapp[i];
    }
    long long l=1,r=n;
    while (l+1<r) {
        long long mid=(l+r)/2;
        if (check(mid)) l=mid;
        else r=mid-1;
    }
    if (check(r)) std::cout<<r<<std::endl;
    else std::cout<<l<<std::endl;

    return 0;
}

// 非常重要的一点是，最后出现次数最多的数字，一定是原先数组里面的一个数字
// 利用前缀和和排序优化是十分重要的一点
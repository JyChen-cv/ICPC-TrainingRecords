/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <ctime>

const long long N=1000000;
struct group {
    long long x;
    long long y;
} mapp[N+2];

bool cmp (group x,group y)
{
    if (x.x<y.x) return 1;
    else if (x.x>y.x) return 0;
    else {
        if (x.y<y.y) return 1;
        else return 0;
    }
}

long long main()
{
    long long n,m;
    std::cin>>n>>m;
    for (long long i=1;i<=m;i++) {
        std::cin>>mapp[i].x>>mapp[i].y;
        if (mapp[i].y<mapp[i].x) {
            i--;
            m--;
        }
    }
    std::sort(mapp+1,mapp+m+1,cmp);
    long long tag=-1,ans=0;
    for (long long i=1;i<=m;i++) {
        if (mapp[i].x>tag) {
            ans+=(mapp[i].x-tag-1);
            tag=mapp[i].y;
        }
        else tag=std::max(tag,mapp[i].y);
    }
    ans+=n-mapp[m].y;
    std::cout<<ans<<std::endl;

    return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <ctime>

const long long N = 1000000;
struct group
{
    long long x;
    long long y;
} mapp[N + 2];

bool cmp(group x, group y)
{
    if (x.x < y.x)
        return 1;
    else if (x.x > y.x)
        return 0;
    else
    {
        if (x.y > y.y)
            return 1;
        else
            return 0;
    }
}

long long main()
{
    long long n;
    long long m;
    scanf("%lld,%d", &n, &m);
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld,%lld", &mapp[i].x, &mapp[i].y);
    }
    std::sort(mapp + 1, mapp + m + 1, cmp);
    long long tag = -1, ans = 0;
    for (long long i = 1; i <= m; i++)
    {
        if (mapp[i].x > tag)
        {
            ans += (mapp[i].y - mapp[i].x + 1);
            tag = mapp[i].y;
        }
        else
        {
            if (mapp[i].y > tag)
            {
                ans += (mapp[i].y - tag);
                tag = mapp[i].y;
            }
        }
    }
    std::cout << n - ans + 1 << std::endl;

    return 0;
}

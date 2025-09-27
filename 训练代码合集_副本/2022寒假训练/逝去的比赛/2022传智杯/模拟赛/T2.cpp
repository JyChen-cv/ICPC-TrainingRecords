#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

long long a=0,b=0,ans=1;

bool check()
{
    long long l1=b%10;
    long long l2=((b-l1)/10)%10;
    if (a<=9) {
        long long l3=a%10;
        return (l3+l1)==(l2*2);
    }
    else {
        long long l3=a%10;
        long long l4=((a-l3)/10)%10;
        // std::cout<<l4<<" "<<l3<<" "<<l2<<" "<<l1<<std::endl;
        if ((l1+l3)==(l2*2) && (l2+l4)==(l3*2)) return 1;
        else return 0;
    }
}

long long main()
{
    long long n;
    std::cin>>n;
    long long ls=n/1440;
    ans+=ls*39;
    n%=1440;
    while (n--) {
        b++;
        if (b==60) {
            b=0;
            a++;
        }
        if (check()) ans++;
    }
    // std::cout<<a<<" "<<b<<std::endl;
    // std::cout<<check()<<std::endl;
    std::cout<<ans<<std::endl;

    return 0;
}
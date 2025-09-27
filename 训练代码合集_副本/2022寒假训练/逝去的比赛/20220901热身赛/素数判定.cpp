#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

// inline bool read(long long & x) 
// {
//     char c=getchar();
//     if (c==EOF) return 0;
//     while (c<'0' || c>'9') c=getchar();
//     while (c>='0' && c<='9') {
//         x=(x<<1)+(x<<3)+(c^48);
//         c=getchar();
//     }
//     return 1;
// }   //？？？

long long main()
{
    // freopen("okok.in","r",stdin);

    long long n;
    while (std::cin>>n) {
        bool tag=0;
        if (n<=0 || n==1) tag=1;
        else if (n==2) tag=0;
        else for (long long i=2;i*i<=n;i++) {
            if (n%i==0) {
                tag=1;
                break;
            }
        }

        if (tag==1) std::cout<<"no"<<std::endl;
        else std::cout<<"yes"<<std::endl;
    }

    return 0;
}
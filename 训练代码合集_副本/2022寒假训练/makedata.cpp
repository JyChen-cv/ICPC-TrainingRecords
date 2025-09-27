#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
long long main()
{
    freopen("data.in","w",stdout);
    srand(time(0));
    long long n=rand()%1000+1;
    std::cout<<n<<std::endl;
    for (long long i=1;i<=n;i++) {
        std::cout<<(std::rand()%1000)<<" ";
    }
    return 0;
}

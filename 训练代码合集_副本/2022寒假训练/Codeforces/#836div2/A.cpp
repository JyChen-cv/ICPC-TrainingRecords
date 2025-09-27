#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

long long main()
{
    long long t;
    std::cin>>t;
    while (t--) {
        std::string mapp;
        std::cin>>mapp;
        std::cout<<mapp;
        for (long long i=(long long)mapp.size()-1;i>=0;i--) std::cout<<mapp[i];
        std::cout<<std::endl;
    }
    return 0;
}
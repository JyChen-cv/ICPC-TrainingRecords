#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

std::string mapp;

long long main()
{
    std::cin>>mapp;
    long long tag=0;
    long long n=(long long)mapp.size()-1;
    while (tag<=n) {
        char ls=0;
        for (long long i=tag;i<=n;i++) {
            if (mapp[i]>ls) {
                ls=mapp[i];
                tag=i+1;
                // std::cout<<mapp[i]<<" "<<ls<<" "<<tag<<std::endl;
            }
        }
        // break;
        std::cout<<mapp[tag-1];
    }

    return 0;
}
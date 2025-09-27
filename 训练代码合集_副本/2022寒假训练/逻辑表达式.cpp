#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

long long main()
{
    std::string mapp;
    std::cin>>mapp;

    long long kuohao=0;
    for (long long i=0;i<(long long)mapp.size();i++) {
        if (mapp[i]=='(') {
            kuohao++;
        }
        else if (mapp[i]==')') {
            kuohao--;
        }
        else if (mapp[i]=='&') {
            
        }
    }

    return 0;
}
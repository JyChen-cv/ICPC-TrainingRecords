#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

std::map<std::string,long long> mapp;

long long main()
{
    std::string c;
    while (1) {
        std::cin>>c;
        if (c=="0") break;
        if (mapp[c]) continue;
        else {
            std::cout<<c;
            mapp[c]=1;
        }
        c.clear();
    }

    return 0;
}
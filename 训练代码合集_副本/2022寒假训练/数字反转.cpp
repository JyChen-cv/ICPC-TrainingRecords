#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

std::string mapp;

long long main()
{
    std::cin >> mapp;
    long long tag = 1;
    if (mapp[0] > '9' || mapp[0] < '1')
        tag = -1;
    long long ans = 0;
    for (long long i = (long long)mapp.size(); i >= 0; i--)
    {
        if (mapp[i] >= '0' && mapp[i] <= '9')
        {
            ans *= 10;
            ans += mapp[i] - '0';
        }
    }
    std::cout << ans * tag << std::endl;

    return 0;
}
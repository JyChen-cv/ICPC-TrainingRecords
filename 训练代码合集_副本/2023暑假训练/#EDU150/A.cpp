#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n;
        std::cin>>n;
        if (n<=4) std::cout<<"Bob"<<std::endl;
        else std::cout<<"Alice"<<std::endl;
    }
    return 0;
}
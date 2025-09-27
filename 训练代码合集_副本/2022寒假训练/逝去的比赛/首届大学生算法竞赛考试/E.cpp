#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

const long long N=20;
long long mapp[20][2][2][2][2];  // 8 2 6 的数量

long long main()
{
    long long n;
    std::cin>>n;
    long long num=0;
    while (n>=std::pow(10,num)) num++;
    std::cout<<num<<std::endl;
    for (long long i=1;i<=num;i++) {
        if (i!=num) {
            mapp[i][]
        }
    }
    return 0;
}
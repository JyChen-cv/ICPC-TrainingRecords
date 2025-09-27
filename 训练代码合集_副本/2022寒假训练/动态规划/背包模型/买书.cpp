#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

const long long N=1000;
long long f[N*10+2],mapp[5]={0,10,20,50,100};  //意思是只能在定义数组的时候才能用大括号？对的

long long main()
{
    long long n;
    std::cin>>n;
    for (long long i=1;i<=4;i++) {
        for (long long j=mapp[i];j<=n;j++) {
            if (j==mapp[i]) f[j]++;
            else if (f[j-mapp[i]]) f[j]+=f[j-mapp[i]];
        }
    }
    std::cout<<f[n]<<std::endl;
    return 0;
}
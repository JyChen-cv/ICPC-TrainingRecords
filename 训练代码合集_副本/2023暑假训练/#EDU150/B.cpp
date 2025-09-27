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
        int tag=0,ls=0,lss;
        std::cin>>ls;
        lss=ls;
        std::cout<<1;
        for (int i=2;i<=n;i++) {
            int a;
            std::cin>>a;
            if (!tag && a>=ls) {
                ls=a;
                std::cout<<1;
            }
            else if (!tag && a<=lss) {
                tag=1;
                ls=a;
                std::cout<<1;
            }
            else if (a>=ls && a<=lss) {
                ls=a;
                std::cout<<1;
            }
            else std::cout<<0;
        }
        std::cout<<std::endl;
    }
    return 0;
}
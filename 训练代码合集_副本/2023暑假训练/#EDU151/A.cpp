#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

int main()
{
    int t;
    std::cin>>t;
    while (t--) {
        int n,k,x;
        std::cin>>n>>k>>x;
        if (k<=1 && x==1) std::cout<<"NO"<<std::endl;
        else if (x!=1) {
            std::cout<<"YES"<<std::endl;
            std::cout<<n<<std::endl;
            for (int i=1;i<=n;i++) {
                std::cout<<1<<" ";
            }
            std::cout<<std::endl;
        }
        else {
            if (n%2==0) {
                std::cout<<"YES"<<std::endl;
                std::cout<<(n/2)<<std::endl;
                for (int i=1;i<=n/2;i++) {
                    std::cout<<2<<" ";
                }
                std::cout<<std::endl;
            }
            else {
                if (x<3) std::cout<<"NO"<<std::endl;continue;
                std::cout<<"YES"<<std::endl;
                n-=3;
                std::cout<<(n/2+1)<<std::endl;
                for (int i=1;i<=n/2;i++) {
                    std::cout<<2<<" ";
                }
                std::cout<<3<<std::endl;
            }
        }
    }
    return 0;
}
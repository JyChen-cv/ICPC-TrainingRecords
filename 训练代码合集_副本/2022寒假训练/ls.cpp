#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

const long long N=100000;
struct group {
    long long pre;
    long long tre;
} mapp[N+2];

long long main()
{
    freopen("data.in","r",stdin);
    long long n=0;
    while (std::cin>>mapp[++n].pre>>mapp[n].tre) ;
    for (long long std=0;std<=10;std++) {
        double TP=0,FP=0,TN=0,FN=0; // 真阳，假阳，真阴，假阴
        for (long long i=1;i<=n;i++) {
            if (mapp[i].tre>=std && mapp[i].pre>=std) {
                TP++;
            }
            else if (mapp[i].tre>=std && mapp[i].pre<std) {
                FN++;
            }
            else if (mapp[i].tre<std && mapp[i].pre>=std) {
                FP++;
            }
            else {
                TN++;
            }
        }
        double TPR=TP/(TP+FN);
        double FPR=TN/(TN+FP);
        // std::cout<<TPR<<",";
        std::cout<<std<<":TPR"<<" "<<TPR<<" "<<":FPR"<<" "<<FPR<<std::endl;
    }

    return 0;
}
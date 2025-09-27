#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

long long month[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
long long main()
{
    long long a,b,c,ans=0;
    scanf("%d/%d/%d",&a,&b,&c);
    c+=2000;
    if ((c%4==0 && c%100!=0) || c%400==0) month[2]++;
    if (a<=12 && a>=1) {
        if (b<=month[a] && b>=1) ans+=1;
    }
    if (b<=12 && b>=1) {
        if (a<=month[b] && a>=1) ans+=2;
    }
    if (ans==3) std::cout<<"BOTH";
    else if (ans==2) std::cout<<"DDMMYY";
    else if (ans==1) std::cout<<"MMDDYY";
    else std::cout<<"NOTHING";

    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

std::string mapp1,mapp2;
const long long mob[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const long long mobb[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool judge(std::string x)
{
    if (x[0]!=x[7]) return 0;
    if (x[1]!=x[6]) return 0;
    if (x[2]!=x[5]) return 0;
    if (x[3]!=x[4]) return 0;
    return 1;
}

bool check(std::string x) 
{
    long long ls=x[0]*1000+x[1]*100+x[2]*10+x[3];
    if ((ls%4==0 && ls%100!=0) || ls%400==0) return 1;
    else return 0;
}

void tomorrow(std::string &x)
{
    long long year=(x[0]-'1'+1)*1000+(x[1]-'1'+1)*100+(x[2]-'1'+1)*10+(x[3]-'1'+1);
    long long month=(x[4]-'1'+1)*10+(x[5]-'1'+1);
    long long day=(x[6]-'1'+1)*10+(x[7]-'1'+1);
    // std::cout<<year<<" "<<month<<" "<<day<<std::endl;
    if (check(x)) {  // 润了
        day++;
        if (day>mobb[month]) {
            month++;
            if (month>12) {
                month=1;
                year++;
            }
            day=1;
        }
    }
    else {
        day++;
        if (day>mob[month]) {
            month++;
            if (month>12) {
                month=1;
                year++;
            }
            day=1;
        }
    }
    

    x[7]=day%10+'1'-1;
    x[6]=((day-(day%10))/10)%10+'1'-1;
    x[5]=month%10+'1'-1;
    x[4]=((month-(month%10))/10)%10+'1'-1;
    x[3]=year%10+'1'-1;
    year-=(year%10);
    year/=10;
    x[2]=year%10+'1'-1;
    year-=(year%10);
    year/=10;
    x[1]=year%10+'1'-1;
    year-=(year%10);
    year/=10;
    x[0]=year%10+'1'-1;
    year-=(year%10);
    year/=10;
}

bool judge2()
{
    for (long long i=0;i<=7;i++) {
        if (mapp1[i]>mapp2[i]) return 1;
        else if (mapp1[i]<mapp2[i]) return 0;
    }
    return 1;
}

long long main()
{
    std::cin>>mapp1>>mapp2;

    long long ans=0;
    for ( ; ; ) {
        
        if (judge(mapp1)) ans++;
        
        tomorrow(mapp1);
        // std::cout<<mapp1<<std::endl;
        if (judge2()) break;
    }

    std::cout<<ans<<std::endl;
    return 0;
}
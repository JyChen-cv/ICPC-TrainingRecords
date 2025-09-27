#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 1e5;
const int mond[20] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
struct group {
    int year, mon, day, h, min, sec;
    long long ls = 0;
    void deal() {
        ls += (day + mond[mon - 1]) * 86400 + h * 3600 + min * 60 + sec;
    }
    bool operator<(const group &t) const {
        if (year < t.year)
            return 1;
        else if (year > t.year)
            return 0;
        else {
            if (mon < t.mon)
                return 1;
            else if (mon > t.mon)
                return 0;
            else {
                if (day < t.day)
                    return 1;
                else if (day > t.day)
                    return 0;
                else {
                    if (h < t.h)
                        return 1;
                    else if (h > t.h)
                        return 0;
                    else {
                        if (min < t.min)
                            return 1;
                        else if (min > t.min)
                            return 0;
                        else {
                            if (sec < t.sec)
                                return 1;
                            else
                                return 0;
                        }
                    }
                }
            }
        }
    }
} mapp[N + 2];

int main() {
    freopen("/Users/chenjiayou/Desktop/2024寒假训练/2024蓝桥杯每日一题/日期问题/3494.in", "r", stdin);
    int n = 1;
    while (scanf("%d-%d-%d %d:%d:%d", &mapp[n].year, &mapp[n].mon, &mapp[n].day, &mapp[n].h, &mapp[n].min, &mapp[n].sec) != EOF) {
        // std::cout<<n<<std::endl;
        mapp[n].deal();
        n++;
    }
    n--;
    std::sort(mapp + 1, mapp + n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i += 2) {
        // std::cout<<i<<" "<<mapp[i].year<<" "<<mapp[i].mon<<" "<<mapp[i].day<<" "<<mapp[i].h<<" "<<mapp[i].min<<" "<<mapp[i].sec<<std::endl;
        // std::cout<<i+1<<" "<<mapp[i+1].year<<" "<<mapp[i+1].mon<<" "<<mapp[i+1].day<<" "<<mapp[i+1].h<<" "<<mapp[i+1].min<<" "<<mapp[i+1].sec<<std::endl;
        ans += mapp[i + 1].ls - mapp[i].ls;
        // std::cout<<mapp[i].sec<<" "<<mapp[i+1].sec<<" "<<mapp[i+1].deal()-mapp[i].deal()<<std::endl;
    }
    std::cout << ans << std::endl;
    std::cout << 5101913 << std::endl;
    return 0;
}
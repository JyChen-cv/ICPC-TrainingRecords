#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef unsigned long long llu;
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        std::vector<llu> mapp, res;
        llu tail = 0;

        int tag = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            llu b;
            scanf("%d%llu", &a, &b);
            if (a == 1) {
                if (tag == 1) continue;
                tail++;
                mapp.push_back(tail);
                res.push_back(b);
            } else {
                if ((llu)1e18 / (b + 1) >= tail && tag == 0)
                    tail *= (b + 1);
                else {
                    tag = 1;
                }
            }
        }
        // for (int i = 0; i < (int)mapp.size(); i++) {
        //     std::cout << mapp[i] << std::endl;
        // }
        for (int i = 1; i <= m; i++) {
            llu a;
            scanf("%llu", &a);
            while (1) {
                int loc = std::lower_bound(mapp.begin(), mapp.end(), a) - mapp.begin();
                // std::cout << a << " " << loc << std::endl;
                if (loc >= (int)mapp.size() || mapp[loc] != a) {
                    a %= mapp[loc - 1];
                    if (a == 0) {
                        printf("%llu ", res[loc - 1]);
                        break;
                    }
                } else {
                    printf("%llu ", res[loc]);
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}

/*
1
12 5
1 6
1 11
2 392130334
1 4
2 744811750
1 10
1 5
2 209373780
2 178928984
1 3
2 658326464
2 1000000000
914576963034536490 640707385283752918 636773368365261971 584126563607944922 1000000000000000000
*/
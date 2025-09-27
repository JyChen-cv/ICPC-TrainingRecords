#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
int mapp[N + 2];
int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            char a;
            std::cin >> a;
            if (a == '1')
                mapp[i] = 1;
            else
                mapp[i] = 0;
        }
        // for (int i = 1; i <= n; i++) std::cout << mapp[i] << " ";
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int j = n + 1 - i;
            if (j <= i) break;
            if (mapp[i] != mapp[j]) cnt++;
        }
        for (int i = 0; i <= n; i++) {
            if (i < cnt)
                std::cout << 0;
            else {
                if (i > (n - cnt))
                    std::cout << 0;
                else {
                    if (n % 2)
                        std::cout << 1;
                    else
                        std::cout << (!((i - cnt) % 2));
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
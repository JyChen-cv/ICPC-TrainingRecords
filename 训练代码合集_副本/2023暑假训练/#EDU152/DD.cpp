#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int mapp[N + 2], she[N + 2], tag[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }

    int k = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!mapp[i]) continue;
        // std::cout << i << std::endl;
        k++;
        for (int j = i; j <= n + 1; j++) {
            if (mapp[j]) {
                she[j] = k;
                tag[k] = std::max(tag[k], mapp[j]);
            } else {
                // std::cout << i << " " << j - 1 << std::endl;
                i = j;
                ans++;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mapp[i])
            continue;
        else {
            if (!mapp[i - 1] && !mapp[i + 1])
                ans++;
            else {
                if (mapp[i - 1] && tag[she[i - 1]])
                    tag[she[i - 1]]--;
                else if (mapp[i + 1] && tag[she[i + 1]])
                    tag[she[i + 1]]--;
                else
                    ans++;
            }
        }
    }
    std::cout << ans << std::endl;
    // for (int i = 1; i <= n; i++) std::cout << tag[i] << " ";
    // std::cout << std::endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        std::vector<int> l1, l2;
        for (int i = 0; i < (int)s1.size(); i++) {
            if (s1[i] == s2[i]) {
                if (s1[i] == '1')
                    l1.push_back(i);
                else
                    l2.push_back(i);
            }
        }

        if (!l1.size() && !l2.size()) {
            std::cout << "NO" << std::endl;
        } else if (!l2.size()) {
            if (l1[0] == 0 && l1[l1.size() - 1] == (int)s1.size() - 1) {
                std::cout << "YES" << std::endl;
            } else
                std::cout << "NO" << std::endl;
        } else if (!l1.size()) {
            if (l2[0] == 0 && l2[l2.size() - 1] == (int)s1.size() - 1) {
                std::cout << "YES" << std::endl;
            } else
                std::cout << "NO" << std::endl;
        } else {
            if (l1[0] == 0) {
                int tt = 0;
                for (int i = 0; i < (int)l1.size(); i++) {
                    int loa = lower_bound(l2.begin(), l2.end(), l1[i]) - l2.begin();
                    if (l2[loa] == l1[i] + 1) {
                        std::cout << "YES" << std::endl;
                        tt = 1;
                        break;
                    }
                }
                if (!tt) std::cout << "NO" << std::endl;
            } else {
                int tt = 0;
                for (int i = 0; i < (int)l2.size(); i++) {
                    int loa = lower_bound(l1.begin(), l1.end(), l2[i]) - l1.begin();
                    if (l1[loa] == l2[i] + 1) {
                        std::cout << "YES" << std::endl;
                        tt = 1;
                        break;
                    }
                }
                if (!tt) std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}
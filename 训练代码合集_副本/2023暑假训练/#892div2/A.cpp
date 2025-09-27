#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::vector<int> m;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            m.push_back(a);
        }
        int tag = 0;
        for (int i = 1; i < (int)m.size(); i++) {
            if (m[i] != m[i - 1]) tag = 1;
        }
        if (tag == 0) {
            std::cout << -1 << std::endl;
        } else {
            std::sort(m.begin(), m.end());
            int num = 1;
            for (int i = (int)m.size() - 1; i >= 1; i--) {
                if (m[i] == m[i - 1])
                    num++;
                else
                    break;
            }
            std::cout << (int)m.size() - num << " " << num << std::endl;
            for (int i = 0; i < (int)m.size(); i++) {
                if (i < (int)m.size() - num) std::cout << m[i] << " ";
            }
            std::cout << std::endl;
            for (int i = 0; i < (int)m.size(); i++) {
                if (i >= (int)m.size() - num) std::cout << m[i] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}
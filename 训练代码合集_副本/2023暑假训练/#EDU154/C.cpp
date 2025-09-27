#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::string l;
        std::cin >> l;
        // if (t>9270) continue;
        // else if (t>=9000) std::cout<<l<<std::endl;
        int al = 0, guan1 = 1, tag = 0;
        std::vector<int> guan;
        for (int i = 0; i < (int)l.size(); i++) {
            if (l[i] == '0') {
                if (al <= guan1) {
                    std::cout << "NO" << std::endl;
                    tag = 1;
                    break;
                } else {
                    if ((int)guan.size()) {
                        if (al != guan[(int)guan.size() - 1])
                            guan.push_back(al);
                    } else
                        guan.push_back(al);
                }
            } else if (l[i] == '1') {
                if (guan.size()) {
                    std::cout << "NO" << std::endl;
                    tag = 1;
                    break;
                }
                guan1 = std::max(1, al);
            } else if (l[i] == '+') {
                al++;
            } else {
                if (guan.size()) {
                    if (al == guan[(int)guan.size() - 1]) {
                        guan.pop_back();
                    }
                }
                al--;
                guan1 = std::min(guan1, std::max(al, 1));
            }
        }
        if (!tag) std::cout << "YES" << std::endl;
    }
    return 0;
}
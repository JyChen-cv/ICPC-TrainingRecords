#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const int N = 1e5;
ll mapp[N + 2];
int main() {
    int n;
    ll m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    std::vector<ll> ans;
    ll right = -1e9;
    for (int i = 1; i <= n; i++) {
        if (mapp[i] >= right) {
            ans.push_back(mapp[i]);
            right = mapp[i] + m;
            // std::cout << mapp[i] << std::endl;
        }
    }
    std::cout << ans.size() << std::endl;
    return 0;
}
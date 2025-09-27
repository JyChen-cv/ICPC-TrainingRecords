#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define inf 1e18;
const int N = 5000;
typedef long long ll;
ll sum[N + 2];

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        ll a;
        std::cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    ll ans = -inf;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = std::max(ans, sum[j] - sum[i - 1]);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

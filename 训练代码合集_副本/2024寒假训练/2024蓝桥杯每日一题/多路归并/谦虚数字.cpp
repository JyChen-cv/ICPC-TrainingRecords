#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;
const int N = 100;
ll mapp[N + 2], t[N + 2];
std::vector<ll> ans;
struct group {
    ll x, y;
    bool operator<(const group t) const {
        return x * ans[y] > t.x * ans[t.y];
    }
};
std::priority_queue<group> q;

int main() {
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    ans.push_back(1);
    for (int i = 1; i <= n; i++) {
        q.push({mapp[i], 0});
    }

    while (k--) {
        // std::cout << ans[ans.size() - 1] << std::endl;
        while (q.top().x * ans[q.top().y] <= ans[ans.size() - 1]) {
            q.push((group){q.top().x, q.top().y + 1});
            q.pop();
        }
        ans.push_back(q.top().x * ans[q.top().y]);
    }
    std::cout << ans[ans.size() - 1] << std::endl;
    return 0;
}
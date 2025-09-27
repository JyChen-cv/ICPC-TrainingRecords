#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

const int N = 1e5;
std::pair<int, int> mapp[N + 2];
#define p first
#define t second
std::stack<std::pair<int, int> > q;

bool check(std::pair<int, int> x, std::pair<int, int> y) {
    if (std::abs(x.p - y.p) <= std::abs(x.t - y.t))
        return 1;
    else
        return 0;
}

int main() {
    // O(nlogn)能行固然美丽，但是O(n)更为绝技
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, len;
    std::cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].p >> mapp[i].t;
    }
    q.push(mapp[1]);
    for (int i = 2; i <= n; i++) {
        while (q.size()) {
            if (check(q.top(), mapp[i])) {
                if (q.top().t > mapp[i].t)
                    q.pop();
                else
                    break;
            } else {
                q.push(mapp[i]);
                break;
            }
        }
        if (q.size() == 0) q.push(mapp[i]);
    }

    int ans = 0;
    std::pair<int, int> tag = q.top();
    q.pop();
    ans = std::max(ans, len - tag.p + tag.t);
    while (q.size()) {
        // std::cout << q.top().p << " " << q.top().t << " " << ans << std::endl;
        int low = std::min(tag.t, q.top().t);
        int hig = std::max(tag.t, q.top().t);
        int dis = std::abs(tag.p - q.top().p);
        int res = (dis - (hig - low)) / 2 + hig;
        // std::cout << low << " " << hig << " " << dis << " " << res << std::endl;
        ans = std::max(ans, res);
        tag = q.top();
        q.pop();
    }
    ans = std::max(ans, tag.p - 1 + tag.t);
    std::cout << ans << std::endl;
    return 0;
}
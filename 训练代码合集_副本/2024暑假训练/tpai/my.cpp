#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define int long long
const int N = 200;
int mp[N + 2][N + 2], v[N + 2][N + 2];
int deal(int x, int y) {
    // 1 1 是输，知道是0
    // 1 x 是胜利，但是不知道是几, 到这里就不能行动了，判定为胜
    // 2 2 ，3 是失败，知道是0 所以作为递归的边界

    // 主要是构造一种SG值，满足初始条件的时候异或为0（ =且判定为负）

    if (x == 1 || y == 1) return 0;
    if (x > y) std::swap(x, y);
    if (x == 2 && y == 2) return 0;
    if (x == 2 && y == 3) return 0;
    if (v[x][y]) return mp[x][y];
    std::vector<int> q;
    for (int i = 2; i < x - 1; i++) {
        q.push_back((deal(i, y) ^ deal(x - i, y)));
    }
    for (int i = 2; i < y - 1; i++) {
        q.push_back((deal(x, i) ^ deal(x, y - i)));
    }
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    int point = 0;
    for (auto i : q) {
        if (i != point) break;
        point++;
    }
    v[x][y] = 1, mp[x][y] = point;
    //     std::cout<<x<<" "<<y<<" "<<point<<std::endl;
    return point;
}
signed main() {
    int a, b;
    // while (scanf("%lld%lld", &a, &b) != EOF) {
    //     int ans = deal(a, b);
    //     puts(ans ? "WIN" : "LOSE");
    // }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            std::cout << deal(i, j) << " ";
        }
        puts("");
    }
    return 0;
}
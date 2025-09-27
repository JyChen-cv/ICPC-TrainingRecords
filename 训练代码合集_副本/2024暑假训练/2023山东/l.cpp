#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int n, xx, yy;
struct group {
    int x, y, len1, len2;
};
std::vector<group> ans;

bool check(int x, int y) {
    if (x == xx || y == yy)
        return 0;
    else
        return 1;
}

void dfs(int x, int y, int sz) {
    if (sz == 1) return;
    if (check(x, y)) {
        ans.push_back({x, y, sz - 1, sz - 1});
        dfs(x + 1, y + 1, sz - 1);
    } else if (check(x + sz - 1, y)) {
        ans.push_back({x + sz - 1, y, -(sz - 1), sz - 1});
        dfs(x, y + 1, sz - 1);
    } else if (check(x, y + sz - 1)) {
        ans.push_back({x, y + sz - 1, sz - 1, -(sz - 1)});
        dfs(x + 1, y, sz - 1);
    } else {
        ans.push_back({x + sz - 1, y + sz - 1, -(sz - 1), -(sz - 1)});
        dfs(x, y, sz - 1);
    }
}

int main() {
    std::cin >> n >> xx >> yy;
    std::cout << "Yes" << std::endl;
    dfs(1, 1, n);
    std::cout << ans.size() << std::endl;
    for (auto i : ans) {
        std::cout << i.x << " " << i.y << " " << i.len1 << " " << i.len2 << std::endl;
    }
    return 0;
}
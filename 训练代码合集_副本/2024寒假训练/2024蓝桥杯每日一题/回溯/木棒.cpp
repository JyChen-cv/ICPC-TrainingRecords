#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int mapp[N + 2], v[N + 2], n;
int len, num;

bool dfs(int x, int y, int lst) {
    // std::cout << x << " " << n << " " << y << " " << num << " " << len << std::endl;
    if (x == num) return 1;
    if (y == len) return dfs(x + 1, 0, 1);
    int tag = 0;
    for (int i = lst; i <= n; i++) {
        if (v[i]) continue;
        if (y + mapp[i] > len || mapp[i] == tag) continue;

        v[i] = 1;
        if (dfs(x, y + mapp[i], i + 1)) return 1;  // 剪枝3:对于同一个拼接后的木棍，所用的长度肯定递减
        v[i] = 0;
        tag = mapp[i];                               // 剪枝4:同一木棍同一长度只用尝试一次即可
        if (y == 0 || y + mapp[i] == len) return 0;  // 剪枝5:当木棍在开头和结尾都不能使用的时候，该方案就失败了
    }
    return 0;
}

bool check(int x, int all) {
    // std::cout << len << " " << all << std::endl;
    memset(v, 0, sizeof v);
    len = x;
    num = all / len;
    return dfs(0, 0, 1);
}

bool cmd(int x, int y) {
    return x > y;
}

int main() {
    while (std::cin >> n, n) {
        int all = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> mapp[i];
            all += mapp[i];
        }
        std::sort(mapp + 1, mapp + n + 1, cmd);  // 剪枝1:从大到小排序
        for (int i = mapp[1]; i <= all; i++) {   // 剪枝2:省略不可用的长度
            if (all % i == 0 && check(i, all)) {
                std::cout << i << std::endl;
                break;
            }
        }
    }
    return 0;
}
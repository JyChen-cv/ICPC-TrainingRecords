#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define x first
#define y second
const int N = 100;
int take[N + 2];
std::pair<int, int> mapp[N + 2];
std::priority_queue<std::pair<int, int>> q;

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        take[i] = take[i - 1] + a;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &mapp[i].x);
    for (int i = 1; i <= n; i++) scanf("%d", &mapp[i].y);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int ls = m - take[i], anss = 0;
        while (q.size()) q.pop();
        for (int j = 1; j <= i; j++) q.push(mapp[j]);
        // while (q.size()) {
        //     std::pair<int, int> l = q.top();
        //     std::cout << l.x << " " << l.y << std::endl;
        //     q.pop();
        // }
        while (ls && q.size()) {
            ls--;
            std::pair<int, int> l;
            l = q.top();
            // std::cout << l.x << " " << l.y << " ?" << std::endl;
            q.pop();
            anss += l.x;
            l.x -= l.y;
            if (l.x == 0)
                continue;
            else
                q.push(l);
        }
        // std::cout << anss << std::endl;
        ans = std::max(anss, ans);
    }
    std::cout << ans << std::endl;
    return 0;
}
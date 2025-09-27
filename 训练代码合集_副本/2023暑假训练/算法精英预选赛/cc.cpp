#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define x first
#define y second
const int N = 100, M = 2e4;
int take[N + 2];
std::pair<int, int> mapp[N + 2];
int f[M + 2];

int main()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        int a;
        scanf("%d", &a);
        take[i] = take[i - 1] + a;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mapp[i].x);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mapp[i].y);
    }

    for (int i = 1; i <= n; i++) {
        if (!mapp[i].y) {
            for (int j = take[i] + 1; j <= m; j++) {
                f[j] = std::max(f[j], f[j - take[i] - 1] + mapp[i].x);
            }
            continue;
        }
        for (int j = m; j >= take[i]; j--) {
            for (int k = min(mapp[i].x / mapp[i].y , j - take[i]); k >= 0; k--) {
                if (j >= take[i] + k) {
                    f[j] = std::max(f[j], f[j - take[i] - k] + (2 * mapp[i].x - (k - 1) * mapp[i].y) * k / 2);
                }
            }
        }
    }
    std::cout << f[m] << std::endl;
    return 0;
}
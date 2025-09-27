#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#define int long long
typedef long long ll;
typedef double db;
typedef std::pair<int, int> PII;
void solve() {
  int n;
  std::cin >> n;
  int num = n / 15;
  int ans = num * 3;
  ans += std::min(n - num * 15 + 1, (ll)3);
  std::cout << ans << std::endl;
}

signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0), std::cout.tie(0);
  int times = 1;
  std::cin >> times;
  while (times--) {
    solve();
  }
  return 0;
}

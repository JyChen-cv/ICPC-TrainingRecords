#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cstring>
#include <set>
#include <bitset>

#define endl '\n'
#define ll long long
#define int long long
using namespace std;
int T;
int n, k;
int mark[500000];
pair<int, int> a[500000];
int ans[500000];

void solve()
{
	cin >> n >> k;
	for (int q = 1; q <= k; q++) cin >> a[q].first >> a[q].second;

	int flag = 1;
	sort(a + 1, a + k + 1);
	if (a[1].first != 1) flag = 0;
	if (a[k].second != n) flag = 0;



	for (int q = 1; q < k; q++) if (a[q + 1].first != a[q].second + 1) flag = 0;
	// cout<<flag<<endl;
	int s = 0;
	for (int q = 1; q <= k; q++) s = max(a[q].second - a[q].first + 1, s);

	int p = 0;
	int cnt = 0;
	for (int q = 1; q <= k; q++) if (s == a[q].second - a[q].first + 1) cnt++, p = q;



	if (cnt > 1) flag = 0;

	if (flag == 0)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}

	int la = 0;
	for (int q = a[p].first; q <= a[p].second; q++) ans[q] = la, la = q;

	for (int q = 1; q <= k; q++) if (q != p)
		{
			la = a[p].first;
			for (int w = a[q].first; w <= a[q].second; w++) ans[w] = la, la = w;
		}

	for (int q = 1; q <= n; q++) cout << ans[q] << " ";
	cout << endl;
}
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
//freopen("a.txt","r",stdin);
//freopen("b.txt","w",stdout);
	cin >> T;
	while (T--) solve();

	return 0;
}








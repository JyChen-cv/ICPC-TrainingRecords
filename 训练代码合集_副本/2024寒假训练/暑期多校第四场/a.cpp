#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

void slove() {
	int n;
	string str;
	cin >> str;

	auto cnt0 = [&]() {
		int res = 0;
		for (auto ch : str) if (ch == '0') res++;
		return res;
	}();

	auto cnt1 = [&]() {
		int res = 0;
		for (auto ch : str) if (ch == '1') res++;
		return res;
	}();

	if (cnt1 == 0 || cnt0 == 0) {
		if (cnt1 == 0) {
			cout << string('1' , n) << endl;
		} else {
			cout << string('0' , n) << endl;
		}
	} else {
		cout << string('1' , n) << endl;
	}


}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);
	int cnt = 1;

	cin >> cnt;

	while (cnt--) {
		slove();
	}
	return 0;
}
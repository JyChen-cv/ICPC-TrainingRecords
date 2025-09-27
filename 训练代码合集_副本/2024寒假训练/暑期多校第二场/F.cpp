#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

typedef long long ll;

int main()
{
	int t;
	std::cin >> t;
	while (t--) {
		long long n, a, b, c , tag = 0;
		std::cin >> n >> a >> b >> c;
		if (a == 1 || a == n) tag++;
		if (b == 1 || b == n) tag++;
		if (c == 1 || c == n) tag++;
		if ((n * n * n + tag) % 2 == 0) std::cout << "Bob" << std::endl;
		else std::cout << "Alice" << std::endl;
	}
	return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int mod = 1e9 + 7;
int gcd(int a, int b) { return b ? a : gcd(b, a % b); }

inline int q_pow(int x, int y) {
	if (y == 0) return 1;
	int mid = q_pow(x, y >> 1);
	if (y % 2)
		return mid * mid % mod * x % mod;
	else
		return mid * mid % mod;
}
inline int inv(int x) { return q_pow(x, mod - 2); }

int main() {
	int a, b;
	std::cin >> a >> b;
	for (int i=1;i<=a;i++) {
        for (int j=1;j<=b;j++) {
            std::cout<<"^ ";
        }
        std::cout<<std::endl;
    }
    return 0;
}

#include <ctime>
#include <iostream>
#include <random>
using namespace std;
#define ll long long
int main() {
    // freopen("/Users/chenjiayou/Desktop/Cpp/students.txt", "w", stdout);
    srand(time(NULL));

    int t = 1;
    std::cout << t << std::endl;
    int n = rand() % 10 + 1;
    int m = rand() % 20 + 1;
    std::cout << n << " " << m << std::endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << (rand() % 100 > 85 ? 1 : 0);
        }
        std::cout << std::endl;
    }
    return 0;
}
#include <ctime>
#include <iostream>
#include <map>
#include <random>
using namespace std;
#define int long long
std::map<std::pair<int, int>, int> q;
signed main() {
    srand(time(0));
    int n = 20;
    std::cout << rand() % n + 2 << " " << rand() % n + 2 << std::endl;
    return 0;
}
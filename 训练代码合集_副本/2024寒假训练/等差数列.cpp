#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {
    int d, dd;

    sscanf("123456abc-1231", "%dabc%d", &d, &dd);
    printf("%d %d\n", d, dd);
    return 0;
}
#include <iostream>
#include <numeric>

using namespace std;

void rutGon(long long &a, long long &b) {
    if (b == 0) return;
    long long ucln = std::gcd(a, b);
    a /= ucln;
    b /= ucln;
    if (b < 0) {
        a = -a;
        b = -b;
    }
}

int main() {
    long long a, b;
    if (!(cin >> a >> b)) return 0;

    rutGon(a, b);
    cout << a << " " << b << endl;
    return 0;
}
// time:O(log n)
// memory:O(1)

#include <iostream>
using namespace std;

unsigned long long giaithua(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    if (n < 0) {
     return -1;
    } else {
        cout << giaithua(n) << endl;
    }
    return 0;
}
// Time:O(n)
// Memory:O(1)

#include <iostream>
#include <vector>

using namespace std;

void xoaPhanTu(vector<int>& a, int k) {
    if (k < 0 || k >= (int)a.size()) return;
    for (int i = k; i < (int)a.size() - 1; i++) {
        a[i] = a[i + 1];
    }
    a.pop_back();
}

// Time:O(n)
// Memory:O(n)

void chenPhanTu(vector<int>& a, int m, int y) {
    if (m < 0 || m > (int)a.size()) return;
    a.push_back(0);
    for (int i = (int)a.size() - 1; i > m; i--) {
        a[i] = a[i - 1];
    }
    a[m] = y;
}

// Time:O(n)
// Memory:O(n)

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int k, m, y;
    cin >> k >> m >> y;

    xoaPhanTu(a, k);
    chenPhanTu(a, m, y);

    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}

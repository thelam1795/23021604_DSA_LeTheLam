#include <iostream>
#include <vector>

using namespace std;

void in(const vector<double>& a) {
    if (a.empty()) return;

    double sum = 0;
    for (double x : a) sum += x;
    double avg = sum / a.size();

    for (double x : a) {
        if (x >= avg) cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    in(a);
    return 0;
}

// time:O(n)
// memory:O(n)

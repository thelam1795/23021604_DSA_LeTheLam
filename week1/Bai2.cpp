#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sapXep(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sapXep(a);
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}
// do phuc tam time:O(n^2)
// memory:O(n)

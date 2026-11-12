#include <iostream>
#include <vector>

using namespace std;

long long tong(const vector<vector<int>>& mat) {
    long long sum = 0;
    for (const auto& row : mat) {
        for (int val : row) sum += val;
    }
    return sum;
}

// Time:O(mxn)
// Memory: O(mxn)
void xoa(vector<vector<int>>& mat, int i) {
    if (i < 0 || i >= (int)mat.size()) return;
    for (int r = i; r < (int)mat.size() - 1; r++) {
        mat[r] = mat[r + 1];
    }
    mat.pop_back();
}
// Time:O(mxn)
// Memory: O(mxn)

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> mat[r][c];
        }
    }

    cout << tong(mat) << endl;

    int i;
    cin >> i;
    xoa(mat, i);

    for (const auto& row : mat) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}

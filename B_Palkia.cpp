#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int m = n / k;

    vector<vector<int>> groups(k);

    int L = 1, R = n;

    for (int i = 0; i < k; i++) {
        // each group gets m numbers
        for (int j = 0; j < m/2; j++) {
            groups[i].push_back(L++);
            groups[i].push_back(R--);
        }
    }

    if (m % 2 == 1) {
        // assign leftover singletons
        for (int i = 0; i < k; i++) {
            groups[i].push_back(L++);
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            cout << groups[i][j];
        }
        cout << "\n";
    }
}

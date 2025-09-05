#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
int C[MAX];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        C[x]++;
    }

    for(int i = 0; i < MAX; i++) {
        while(C[i]--) cout << i << " ";
    }
}
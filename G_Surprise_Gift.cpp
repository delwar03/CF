#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 3e5 + 10;

void solve() {
    int n; cin>>n;
    int arr[n][n];
    int row[n] = {}, col[n] = {};
    int x = 1024 - (n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = 1;
        }
    }
    bool f;
    if(n % 2 == 0) {
        // arr[0][0] = x;
        // row[0] = col[0] = 1;
        // arr[1][n - 2] = x;
        // row[1] = col[n - 2] = 1;
        arr[n / 2][n - 1 - n / 2] = x;
        row[n / 2] = col[n - 1 - n / 2] = 1;
        f = true;
    } else {
        arr[n / 2][n / 2] = x;
        row[n / 2] = col[n / 2] = 1;
        f = true;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i ^ j) {
                if(row[i] == 0 && col[j] == 0) {
                    if(f && j == n - 1 - i) continue;
                    arr[i][j] = x;
                    row[i] = col[j] = 1;
                    if(j == n - 1 - i) f = true;
                }
            }
        }
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == x) cout<<"# ";
            else cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cerr<<"f: "<<f<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n = 3;
    vector<string> v(n);
    for(auto &x : v) cin>>x;

    int x = 0, o = 0;
    for(auto s : v) {
        for(auto ch : s) {
            if(ch == 'X') x++;
            else if(ch == '0') o++;
        }
    }
    if(x > o + 1 || x < o) {
        cout<<"illegal"<<endl;
    } else {
        int cnt1 = 0, cnt2 = 0;
        int f1 = 0, f2 = 0;
        // row
        for(int i = 0; i < n; i++) {
            cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < n; j++) {
                if(v[i][j] == 'X') {
                    cnt1++;
                } else if(v[i][j] == '0') {
                    cnt2++;
                }
            }
            if(cnt1 == 3) {
                f1 = 1;
            } else if(cnt2 == 3) {
                f2 = 1;
            }
        }
        // col
        for(int i = 0; i < n; i++) {
            cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < n; j++) {
                if(v[j][i] == 'X') {
                    cnt1++;
                } else if(v[j][i] == '0') {
                    cnt2++;
                }
            }
            if(cnt1 == 3) {
                f1 = 1;
            } else if(cnt2 == 3) {
                f2 = 1;
            }
        }
        // diag 1
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(v[i][i] == 'X') {
                cnt1++;
            } else if(v[i][i] == '0') {
                cnt2++;
            }
            if(cnt1 == 3) {
                f1 = 1;
            } else if(cnt2 == 3) {
                f2 = 1;
            }
        }
        // diag 2
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(v[i][n - 1 - i] == 'X') {
                cnt1++;
            } else if(v[i][n - 1 - i] == '0') {
                cnt2++;
            }
            if(cnt1 == 3) {
                f1 = 1;
            } else if(cnt2 == 3) {
                f2 = 1;
            }
        }
        if(f1 && f2) {
            cout<<"illegal"<<endl;
        } else if(f1) {
            if(x == o + 1) {
                cout<<"the first player won"<<endl;
            } else {
                cout<<"illegal"<<endl;
            }
        } else if(f2) {
            if(x == o) {
                cout<<"the second player won"<<endl;
            } else {
                cout<<"illegal"<<endl;
            }
        } else {
            if(x + o == 9) {
                cout<<"draw"<<endl;
            } else {
                if(x == o) {
                    cout<<"first"<<endl;
                } else {
                    cout<<"second"<<endl;
                }
            }
        }
    }
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
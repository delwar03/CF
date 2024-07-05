#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    string a, b; cin>>a>>b;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int n = a.size();
    deque<char> dq1, dq2;
    for(int i = 0; i < (n + 1) / 2; i++) {
        dq1.push_back(a[i]);
    }
    for(int i = 0; i < n / 2; i++) {
        dq2.push_back(b[i]);
    }
    string forw, rev;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(dq1[0] >= dq2[0]) {
                rev.push_back(dq1.back());
                dq1.pop_back();
            } else {
                forw.push_back(dq1[0]);
                dq1.pop_front();
            }
        } else {
            if(dq1[0] >= dq2[0]) {
                rev.push_back(dq2.back());
                dq2.pop_back();
            } else {
                forw.push_back(dq2[0]);
                dq2.pop_front();
            }
        }
    }

    reverse(rev.begin(), rev.end());
    cout<<forw + rev<<endl;
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
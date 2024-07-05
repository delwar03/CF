#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e12 + 10;

void solve() {
    int n; cin>>n;
    int odd = 0, even = 0;
    vector<int> v(n);
    for(auto &x : v) {
        cin>>x;
        odd += (x & 1);
    }
    even = n - odd;
    int mx_even_can_take = (even + 1) / 2;
    int mx_odd_can_take = (odd + 1) / 2;
    int have_to_take = (n + 1) / 2;
    for(int i = 0; i <= mx_odd_can_take; i += 2) {
        int now_even = have_to_take - i;
        if(now_even <= mx_even_can_take) {
            cout<<"Alice"<<endl;
            return;
        }
    }
    cout<<"Bob"<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; cin>>t;
    while(t--) {
        solve();
    }
}

/*
i/p: 
o/p: 
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<vector<int>> s(BLK + 5);

    for(int i = 0; i < n; i++) {
        s[i / BLK].push_back(v[i]);
    }

    for(auto &it : s) {
        sort(it.begin(), it.end());
    }

    // for(auto x : s) {
    //     for(auto y : x) cerr<<y<<" "; cerr<<endl;
    // }

    auto query = [&] (int l, int r, int x) {
        int L = l / BLK, R = r / BLK, res = 0;
        while(l <= r) {
            if(l % BLK == 0 && l + BLK - 1 <= r) {
                int ind = lower_bound(s[l / BLK].begin(), s[l / BLK].end(), x) - s[l / BLK].begin();
                res += BLK - ind;
                l += BLK;
            } else {
                res += (v[l] >= x);
                l++;
            }
        }
        return res;
    };

    auto update = [&] (int i, int x) {
        int I = i / BLK;
        int ind = lower_bound(s[I].begin(), s[I].end(), v[i]) - s[I].begin();
        s[I][ind] = v[i] = x;
        sort(s[I].begin(), s[I].end());
    };

    int q; cin>>q;
    while(q--) {
        int ty; cin>>ty;
        if(ty == 0) {
            int l, r, x; cin>>l>>r>>x;
            --l; --r;
            cout<<query(l, r, x)<<endl;
        } else {
            int i, x; cin>>i>>x;
            --i;
            update(i, x);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
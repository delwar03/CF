#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, q; cin>>n>>m>>q;

    vector<set<int>> row(n), col(m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }
    
    int ans = n * m;

    auto upd = [&] (int i, int j) {
        ans--;
        row[i].erase(j);
        col[j].erase(i);
    };


    while(q--) {
        int r, c; cin>>r>>c;
        --r; --c;
        if(row[r].count(c)) {
            upd(r, c);
        } else {
            auto it = row[r].upper_bound(c);
            if(it != row[r].begin()) {
                upd(r, *prev(it));
            }
            if(it != row[r].end()) {
                upd(r, *it);
            }

            it = col[c].upper_bound(r);
            if(it != col[c].begin()) {
                upd(*prev(it), c);
            }
            if(it != col[c].end()) {
                upd(*it, c);
            }
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
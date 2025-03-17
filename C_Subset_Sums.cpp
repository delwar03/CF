#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 320;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<N> mark[BLK + 10];
int cnt[N][BLK + 10];
long long add[N], lz[N];

void solve() {
    int n, m, q; cin>>n>>m>>q;
    vector<long long> v(n);
    for(auto &x : v) cin>>x;

    vector<vector<int>> sets(m);
    vector<long long> sm(m);
    vector<int> heavy;

    for(int i = 0; i < m; i++) {
        int k; cin>>k;
        if(k >= BLK) heavy.push_back(i);
        for(int j = 0; j < k; j++) {
            int x; cin>>x;
            --x;
            sm[i] += v[x];
            sets[i].push_back(x);
        }
    }

    for(int i = 0; i < (int) heavy.size(); i++) {
        int id = heavy[i];
        for(auto x : sets[id]) {
            mark[i][x] = 1;
        }
    }

    for(int i = 0; i < m; i++) {
        for(auto x : sets[i]) {
            for(int j = 0; j < (int) heavy.size(); j++) {
                if(mark[j][x]) cnt[i][j]++;
            }
        }
    }

    auto upd = [&] (int i, int x) {
        if(sets[i].size() >= BLK) {
            lz[i] += x;
        } else {
            for(auto id : sets[i]) {
                v[id] += x;
            }
        }
        for(int j = 0; j < (int) heavy.size(); j++) {
            add[heavy[j]] += 1LL * cnt[i][j] * x;
        }
    };

    auto qur = [&] (int i) {
        long long ret = 0;
        if(sets[i].size() >= BLK) {
            ret += sm[i];
            ret += add[i];
        } else {
            for(auto id : sets[i]) {
                ret += v[id];
            }
            for(int j = 0; j < (int) heavy.size(); j++) {
                ret += 1LL * cnt[i][j] * lz[heavy[j]];
            }
        }
        return ret;
    };

    while(q--) {
        char ty; cin>>ty;
        if(ty == '?') {
            int k; cin>>k;
            --k;
            cout<<qur(k)<<endl;
        } else {
            int k, x; cin>>k>>x;
            --k;
            upd(k, x);
        }
    }
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
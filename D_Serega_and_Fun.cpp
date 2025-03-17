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
const int N = 2e5 + 10;
const int INF = 1e9 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<deque<int>> cur(BLK + 10);
    vector<vector<int>> freq(BLK + 10, vector<int>(n + 1));

    for(int i = 0; i < n; i++) {
        cur[i / BLK].push_back(v[i]);
        freq[i / BLK][v[i]]++;
    }

    auto upd = [&] (int l, int r) {
        int L = l / BLK, R = r / BLK;
        int lb = l % BLK, rb = r % BLK;

        if(L == R) {
            assert(lb <= rb);
            int tmp = cur[R][rb];
            for(int i = rb; i > lb; i--) cur[L][i] = cur[L][i - 1];
            cur[L][lb] = tmp;
        } else {
            int tmp = cur[R][rb], bk = cur[R - 1].back();

            for(int i = rb; i > 0; i--) cur[R][i] = cur[R][i - 1];
            freq[R][tmp]--;
            cur[R][0] = bk;
            freq[R][bk]++;

            for(int i = R - 1; i > L; i--) {
                freq[i][bk]--;
                int curBk = cur[i - 1].back();
                freq[i][curBk]++;
                cur[i].pop_back();
                cur[i].push_front(curBk);
                bk = curBk;
            }

            freq[L][bk]--;
            for(int i = BLK - 1; i > lb; i--) cur[L][i] = cur[L][i - 1];
            cur[L][lb] = tmp;
            freq[L][tmp]++;
        }
    };

    auto qur = [&] (int l, int r, int k) {
        int L = l / BLK, R = r / BLK, ret = 0;
        int lb = l % BLK, rb = r % BLK;

        if(L == R) {
            for(int i = lb; i <= rb; i++) ret += (cur[L][i] == k);
        } else {
            for(int i = lb; i < (int) cur[L].size(); i++) ret += (cur[L][i] == k);

            for(int i = L + 1; i < R; i++) ret += freq[i][k];

            for(int i = 0; i <= rb; i++) ret += (cur[R][i] == k);
        }

        return ret;
    };

    int q, prv = 0; cin>>q;
    while(q--) {
        int ty; cin>>ty;
        if(ty == 1) {
            int l, r; cin>>l>>r;
            l = (l + prv - 1) % n + 1;
            r = (r + prv - 1) % n + 1;
            --l; --r;
            if(l > r) swap(l, r);
            upd(l, r);
        } else {
            int l, r, k; cin>>l>>r>>k;
            l = (l + prv - 1) % n + 1;
            r = (r + prv - 1) % n + 1;
            k = (k + prv - 1) % n + 1;
            --l; --r;
            if(l > r) swap(l, r);
            prv = qur(l, r, k);
            cout<<prv<<endl;
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
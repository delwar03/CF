#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string str = "narek";
set<char> st = {'n', 'a', 'r', 'e', 'k'};

int dp[N][5]; // (ind, prv)
string arr[N];
bitset<26> bst;

void solve() {
    int n, m; cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>arr[i];

    for(int i = 0; i <= n; i++) for(int j = 0; j < 5; j++) dp[i][j] = -INF;

    function<int(int, int)> magic = [&] (int ind, int prv) {
        if(ind == n) return -prv;
        int &ans = dp[ind][prv];
        if(ans != -INF) return ans;

        ans = magic(ind + 1, prv);

        int tot = 0, nt = 0, f = 0, ls = prv;

        for(auto ch : arr[ind]) {
            if(bst[ch - 'a']) {
                tot++;
                if(ch == str[ls]) {
                    ls++;
                    f++;
                    if(ls == 5) {
                        nt += 5;
                        ls = 0;
                    }
                }
            }
        }

        ans = max(ans, nt - (tot - f) + magic(ind + 1, ls));

        return ans;
    };

    cout<<magic(0, 0)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(char ch = 'a'; ch <= 'z'; ch++) {
        if(st.count(ch)) {
            bst.set(ch - 'a');
        }
    }

    // for(int i : freq) cerr<<i<<" ";
    // cerr<<bst<<endl;

    int t = 1, c = 1; cin>>t;
    for(int i = 1; i <= t; i++) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
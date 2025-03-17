#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, q; cin>>n>>q;
    string a, b; cin>>a>>b;

    map<char, vector<int>> mp1, mp2;

    vector<int> v(n + 1, 0);

    for(char ch = 'a'; ch <= 'z'; ch++) {
        mp1[ch] = mp2[ch] = v;
    }

    for(int i = 1; i <= n; i++) {
        mp1[a[i - 1]][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        mp2[b[i - 1]][i] = 1;
    }

    for(char ch = 'a'; ch <= 'z'; ch++) {
        for(int i = 1; i <= n; i++) {
            mp1[ch][i] += mp1[ch][i - 1];
            mp2[ch][i] += mp2[ch][i - 1];
        }
    }

    // for(auto it : mp1) {
    //     cerr<<it.first<<" -> ";
    //     for(auto x : it.second) cerr<<x<<" "; cerr<<endl;
    // }

    while(q--) {
        int l, r; cin>>l>>r;
        // --l; --r;
        int cnt = 0;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int left = mp1[ch][r] - mp1[ch][l - 1];
            int right = mp2[ch][r] - mp2[ch][l - 1];
            cnt += abs(right - left);
        }
        cout<<cnt / 2<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/

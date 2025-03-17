#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, s, f = 0; 
vector<int> a, b;
int dp[105][10005];

int magic(int ind, int tot, string tmp = "") {
    if(ind == n) {
        if(tot == 0) {
            cout<<"Yes"<<endl;
            cout<<tmp<<endl;
            f = 1;
        }
        return (tot == 0);
    }
    if(f) return 0;
    int &ans = dp[ind][tot];
    if(~ans) return ans;
    ans = 0;
    ans |= magic(ind + 1, tot - a[ind], tmp + "H");
    ans |= magic(ind + 1, tot - b[ind], tmp + "T");
    return ans;
}

void solve() {
    cin>>n>>s;
    a.resize(n); b.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i]>>b[i];
    memset(dp, -1, sizeof dp);
    string tmp;
    if(magic(0, s, tmp)) {
        // cout<<"Yes"<<endl;
        // cout<<tmp<<endl;
    } else {
        cout<<"No"<<endl;
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
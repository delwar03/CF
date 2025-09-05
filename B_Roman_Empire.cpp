#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> val = {1, 5, 10, 50, 100, 500, 1000};
vector<char> roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

map<string, string> mp = {
    {"IIII", "IV"},
    {"VIV", "IX"},
    {"XXXX", "XL"},
    {"LXL", "XC"},
    {"CCCC", "CD"},
    {"DCD", "CM"}
};

void solve() {
    int n; cin >> n;
    string ans = "";
    for(int i = 6; i >= 0; i--) {
        while(n >= val[i]) n -= val[i], ans += roman[i];
    }

    for(int i = 0; i + 3 < sz(ans); i++) {
        if(mp.count(ans.substr(i, 4))) ans.replace(i, 4, mp[ans.substr(i, 4)]);
    }
    for(int i = 0; i + 2 < sz(ans); i++) {
        if(mp.count(ans.substr(i, 3))) ans.replace(i, 3, mp[ans.substr(i, 3)]);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t = 1; cin>>t;
    for(int tc = 1; tc <= t; tc++) {
        // cerr<<"Case "<<tc<<": \n";
        solve();
    }
}
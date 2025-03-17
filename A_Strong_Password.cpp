#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    string s; cin>>s;
    int n = s.size();
    string ans = "";
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            for(int j = 0; j < i; j++) ans += s[j];
            char ch = (s[i] == 'z' ? s[i] - 1 : s[i] + 1);
            ans += ch;
            for(int j = i; j < n; j++) ans += s[j];
            break;
        }
    }

    if(ans.size()) {
        cout<<ans<<endl;
    } else {
        char ch = (s[0] == 'z' ? s[0] - 1 : s[0] + 1);
        cout<<ch<<s<<endl;
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

#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    string a, b; cin>>a>>b;
    int n = a.size();
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            string tmp = a;
            swap(tmp[i], tmp[j]);
            if(stoll(tmp) > stoll(a) && stoll(tmp) <= stoll(b)) {
                a = tmp;
            }
        }
    }

    cout<<a<<endl;
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

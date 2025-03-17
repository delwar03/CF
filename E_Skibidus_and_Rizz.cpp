#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
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

void solve() {
    int n, m, k; cin>>n>>m>>k;

    if(max(n, m) < k) {cout<<-1<<endl; return; }

    string s;
    (n > m ? (s += string(k, '0'), n -= k) : (s += string(k, '1'), m -= k));

    while(n || m) {
        if(s.back() == '1' && n) {
            s += '0'; n--;
        } else {
            if(m) {
                s += '1'; m--;
            } else {
                s += '0'; n--;
            }
        }
    }

    int sm = 0;

    for(auto ch : s) {
        sm += (ch == '0' ? -1 : 1);
        if(abs(sm) > k) {cout<<-1<<endl; return; }
    }

    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
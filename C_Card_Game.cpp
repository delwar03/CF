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
    int n; cin>>n;
    string s; cin>>s;
    set<int> A, B;
    int mxA = 0, mxB = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') A.insert(i + 1), mxA = max(mxA, i + 1);
        else B.insert(i + 1), mxB = max(mxB, i + 1);
    }

    if(mxA > mxB) {
        if(B.count(1)) {
            auto it = A.find(mxA);
            if(it == A.begin()) {
                cout<<"Bob"<<endl;
            } else {
                --it;
                cout<<(*it > mxB ? "Alice" : "Bob")<<endl;
            }
        } else {
            cout<<"Alice"<<endl;
        }
    } else {
        if(A.count(1)) {
            cout<<(sz(B) == 1 ? "Alice" : "Bob")<<endl;
        } else {
            cout<<"Bob"<<endl;
        }
    }
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
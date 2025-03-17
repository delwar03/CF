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
    vector<int> A(n), B(n);
    for(auto &x : A) cin>>x;
    for(auto &x : B) cin>>x;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0LL);
    sort(ord.begin(), ord.end(), [&] (int i, int j) {
        if(A[i] != A[j]) return A[i] > A[j];
        return B[i] < B[j];
    });

    o_set<pii> st;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && A[ord[j]] == A[ord[i]] && B[ord[j]] == B[ord[i]]) st.insert({B[ord[j]], j}), j++;
        ans += (j - i) * st.order_of_key({B[ord[i]], n});
        i = j - 1;
    }

    cout<<ans<<endl;
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
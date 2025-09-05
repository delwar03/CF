#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define int long long
#define endl '\n'
#define F first
#define S second
#define pii pair<int, int>
#define sz(x) (int) x.size()
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<N> prime;
vector<int> st;

void solve() {
    int n; cin>>n;
    int cnt = 0, it = 0;
    for(int x : st) {
        if(2 * x <= n && n - x >= 2) {
            if(!prime[n - x]) cnt++;
        } else {
            break;
        }
    }
    cout<<cnt<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i < N; i++) {
        if(prime[i]) continue;
        for(int j = 2 * i; j < N; j += i) {
            if(!prime[j]) prime[j] = 1;
        }
    }

    for(int i = 2; i < N; i++) if(!prime[i]) st.push_back(i);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
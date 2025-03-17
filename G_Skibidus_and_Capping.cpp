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

int prime[N];
vector<int> di[N];
set<int> st;

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    vector<int> freq(n + 1), two(n + 1);
    int ans = 0, cnt = 0;
    for(int x : v) {
        if(prime[x] == x) {
            ans += cnt++ - freq[x];
            ans += two[x];
        } else {
            int d = x / prime[x];
            if(prime[d] == d) {
                ans += 1 + freq[prime[x]] + freq[x];
                two[prime[x]]++;
                if(d != prime[x]) ans += freq[d], two[d]++;
            } else {
                // 
            }
        }
        freq[x]++;
        // cerr<<"ans: "<<ans<<endl;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < N; i++) di[i].push_back(1), prime[i] = i;

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            if(prime[j] == j) prime[j] = i;
        }
    }

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) st.insert(i);
        for(int j = i; j < N; j += i) {
            di[j].push_back(i);
        }
    }

    // for(int i = 1; i <= 10; i++) {
    //     cerr<<i<<", "<<prime[i]<<" -> ";
    //     for(int x : di[i]) cerr<<x<<" "; cerr<<endl;
    // }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
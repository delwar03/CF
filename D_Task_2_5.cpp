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
const int N = 2e2 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int prime[N];

void solve() {
    int n; cin>>n;
    map<int, int> mp;
    for(int i = 2; i <= n; i++) {
        int tmp = i;
        while(tmp > 1) {
            int d = prime[tmp];
            while(tmp % d == 0) mp[d]++, tmp /= d;
        }
    }

    cout<<n<<" = ";
    for(auto it = mp.begin(); it != mp.end(); it++) {
        cout<<(*it).F<<" ("<<(*it).S<<")";
        if(it != prev(mp.end())) cout<<" * ";
        else cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(prime, prime + N, 0LL);
    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = 2 * i; j < N; j += i) {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }

    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}
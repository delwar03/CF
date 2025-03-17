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
const int N = 2e6 + 10;
const int INF = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int siv[N];
vector<int> prm;

void solve() {
    int n; cin>>n;
    int sq = sqrtl(n);

    int ans = 0;

    for(int i = 0; i < sz(prm); i++) {

        auto get = [&] (int i) {
            int lo = 0, hi = i - 1, best = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(prm[mid] * prm[i] <= sq) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            return best;
        };
        
        ans += get(i) + 1;
    }

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(siv, siv + N, 0LL);

    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            if(siv[j] == j) siv[j] = i;
        }
    }

    for(int i = 2; i < N; i++) if(siv[i] == i) prm.push_back(i);

    // for(int i = 0; i <= 10; i++) cerr<<prm[i]<<" "; cerr<<endl;

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}
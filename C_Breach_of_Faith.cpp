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
    vector<int> v(2 * n);
    for(auto &x : v) cin>>x;
    sort(v.rbegin(), v.rend());
    set<int> st(v.begin(), v.end());

    vector<int> a, b;
    int sm = 0;
    for(int i = 0; i < 2 * n; i++) {
        if(i < n) a.push_back(v[i]), sm += v[i];
        else b.push_back(v[i]), sm -= v[i];
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    // for(int x : a) cerr<<x<<' '; cerr<<endl;
    // for(int x : b) cerr<<x<<' '; cerr<<endl;

    if(n == 1) {
        if(!st.count(sm)) {
            cout<<sm<<" "<<v[0]<<" "<<v[1]<<endl;
        } else {
            cout<<v[1]<<" "<<v[0] + v[1]<<" "<<v[0]<<endl;
        }
        return;
    }

    if(n == 2) {
        if(!st.count(sm)) {
            cout<<sm<<" ";
            for(int i = 0; i < 2 * n; i++) {
                cout<<(i % 2 == 0 ? a[i / 2] : b[i / 2])<<" \n"[i == 2 * n - 1];
            }
        } else {
            int f = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    int d = -a[i] + b[j];
                    if(sm + 2 * d > 0 && !st.count(sm + 2 * d)) {
                        sm += 2 * d;
                        swap(a[i], b[j]);
                        f = 1;
                        // cerr<<i<<' '<<j<<endl;
                        break;
                    }
                }
                if(f) break;
            }
            if(f) {
                cout<<sm<<" ";
                for(int i = 0; i < 2 * n; i++) {
                    cout<<(i % 2 == 0 ? a[i / 2] : b[i / 2])<<" \n"[i == 2 * n - 1];
                }
            } else {
                int id = -1;
                for(int i = 0; i < n; i++) {
                    if(!st.count(sm + 2 * b[i])) {
                        sm += 2 * b[i];
                        f = 1;
                        id = i;
                        break;
                    }
                }
                assert(f);
                // cerr<<sm<<endl;
                cout<<b[id]<<" "<<sm<<" "<<a[0]<<" "<<b[!id]<<" "<<a[1]<<endl;
            }
        }
        return;
    }

    // cerr<<sm<<endl;

    // for(int x : a) cerr<<x<<" "; cerr<<endl;
    // for(int x : b) cerr<<x<<" "; cerr<<endl;
    // cerr<<endl;

    if(st.count(sm)) {
        int f = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int d = -a[i] + b[j];
                if(sm + 2 * d > 0 && !st.count(sm + 2 * d)) {
                    sm += 2 * d;
                    swap(a[i], b[j]);
                    f = 1;
                    // cerr<<i<<' '<<j<<endl;
                    break;
                }
            }
            if(f) break;
        }
    }

    // int ss = 0;

    // for(int x : a) cerr<<x<<" ", ss += x; cerr<<endl;
    // cerr<<ss<<endl;
    // for(int x : b) cerr<<x<<" ", ss -= x; cerr<<endl;
    // cerr<<ss<<endl;

    cout<<sm<<" ";
    for(int i = 0; i < 2 * n; i++) {
        cout<<(i % 2 == 0 ? a[i / 2] : b[i / 2])<<" \n"[i == 2 * n - 1];
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
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
    string s; cin>>s;
    int n = sz(s);
    vector<vector<int>> freq(26, vector<int>(n));

    for(int j = 0; j < 26; j++) {
        for(int i = 0; i < n; i++) {
            freq[j][i] = (i - 1 >= 0 ? freq[j][i - 1] : 0) + (s[i] - 'a' == j);
        }
    }

    auto f = [&] (int l) {
        for(int i = 0; i + l <= n; i++) {
            // i ... (i + l - 1)
            int lb = i, rb = i + l - 1;
            int l = 0, r = n - 1;
            while(l < r && l < lb && r > rb && s[l] == s[r]) l++, r--;
            if(l < lb && r > rb) continue;
            if((lb <= l && l <= rb) && (lb <= r && r <= rb)) return true;
            
            int bad = 0;
            
            map<int, int> cnt;
            
            while(l < r) {
                if(l > rb || r < lb) break;
                if(lb <= l && l <= rb) {
                    int f = s[r] - 'a';
                    // if(i == 3) cerr<<"l: "<<l<<", r: "<<r<<", f: "<<f<<endl;
                    if(freq[f][rb] - (lb - 1 >= 0 ? freq[f][lb - 1] : 0) >= cnt[f] + 1) {
                        cnt[f]++;
                        l++, r--;
                    } else {
                        bad = 1;
                        break;
                    }
                } else {
                    int f = s[l] - 'a';
                    if(freq[f][rb] - (lb - 1 >= 0 ? freq[f][lb - 1] : 0) >= cnt[f] + 1) {
                        cnt[f]++;
                        l++, r--;
                    } else {
                        bad = 1;
                        break;
                    }
                }
                if((lb <= l && l <= rb) && (lb <= r && r <= rb)) return true;
            }
            if(bad) continue;
            while(l < r) {
                if(s[l] != s[r]) {
                    bad = 1;
                    break;
                }
                l++, r--;
            }
            if(!bad) return true;
        }
        return false;
    };

    int lo = 0, hi = n, best = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(f(mid)) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout<<best<<endl;
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
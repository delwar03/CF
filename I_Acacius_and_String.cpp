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

string tmp = "abacaba";

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    auto f = [&] (int i) {
        for(int j = 0; j <= 6; j++) {
            if(s[i + j] != tmp[j]) return false;
        }
        return true;
    };

    int cnt = 0;
    for(int i = 0; i + 6 < n; i++) {
        if(f(i)) {
            cnt += 1;
        }
    }

    if(cnt > 1) {cout<<"No"<<endl; return; }
    if(cnt == 1) {
        for(auto &ch : s) if(ch == '?') ch = 'z';
        cout<<"Yes"<<endl;
        cout<<s<<endl;
        return;
    }


    auto chk = [&] (int i) {
        for(int j = 0; j <= 6; j++) {
            if(s[i + j] != tmp[j] && s[i + j] != '?') return false;
        }
        if(i - 4 >= 0) {
            int f = 1;
            for(int j = 1; j <= 4; j++) {
                if(s[i - j] != tmp[j + 2]) {
                    f = 0;
                    break;
                }
            }
            if(f) return false;
        }
        if(i - 6 >= 0) {
            int f = 1;
            for(int j = 1; j <= 6; j++) {
                if(s[i - j] != tmp[j]) {
                    f = 0;
                    break;
                }
            }
            if(f) return false;
        }

        
        if(i + 4 + 6 < n) {
            int f = 1;
            for(int j = 1; j <= 4; j++) {
                if(s[i + j + 6] != tmp[j + 2]) {
                    f = 0;
                    break;
                }
            }
            if(f) return false;
        }
        if(i + 6 + 6 < n) {
            int f = 1;
            for(int j = 1; j <= 6; j++) {
                if(s[i + 6 + j] != tmp[j]) {
                    f = 0;
                    break;
                }
            }
            if(f) return false;
        }

        return true;
    };

    for(int i = 0; i + 6 < n; i++) {
        if(chk(i)) {
            auto cur = s;
            for(int j = 0; j <= 6; j++) s[i + j] = tmp[j];
            for(int j = i + 7; i < n; i++) if(s[i] == '?') s[i] = 'z';
            cout<<"Yes"<<endl;
            cout<<s<<endl;
            return;
        }
        if(s[i] == '?') s[i] = 'z';
    }

    cout<<"No"<<endl;
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
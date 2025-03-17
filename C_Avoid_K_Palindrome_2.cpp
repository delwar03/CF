#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;

    sort(s.begin(), s.end());

    auto isPalin = [&] (string s) {
        int l = 0, r = k - 1;
        while(r < n) {
            int f = 1, i = l, j = r;
            while(i < j) {
                if(s[i++] != s[j--]) f = 0;
            }
            if(f) return false;
            l++;
            r++;
        }
        return true;
    };

    int ans = 0;
    do {
        ans += isPalin(s);
    } while(next_permutation(s.begin(), s.end()));

    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
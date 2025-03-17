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

string magic(int n) {
    string s = to_string(n);
    int l = 0, r = s.size() - 1;
    int f = 1;
    for(auto ch : s) if(ch == '0') f = 0;
    while (l < r) {
        if(s[l++] != s[r--]) f = 0;
    }

    if(f) return s;

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            string x = to_string(i);
            f = 0;
            for(auto ch : x) if(ch == '0') f = 1;
            if(f) continue;

            int m = n / i;
            string y = x;
            reverse(y.begin(), y.end());
            int j = stoll(y);

            if(m % j == 0) {
                m /= j;
                auto mid = magic(m);
                if(mid.size())
                    return x + "*" + mid + "*" + y;
            }
        }
    }
    return "";
}

void solve() {
    int n; cin>>n;
    auto ans = magic(n);
    
    if(ans.size()) {
        cout<<ans<<endl;
    } else {
        cout<<-1<<endl;
    }
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
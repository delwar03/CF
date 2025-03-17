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
    int n; cin>>n;
    if(n == 1) {cout<<0<<endl; return; }
    n--;

    for(int len = 1; ; len++) {
        int f = (len - 1) / 2, cur = 9;
        for(int i = 1; i <= f; i++) cur *= 10;

        if(n <= cur) {
            string tmp = to_string(cur / 9 + n - 1);
            string num(len, '?');
            for(int i = 0; i < (int) tmp.size(); i++) num[i] = tmp[i];
            for(int i = (int) tmp.size(); i < len; i++) num[i] = num[len - 1 - i];

            cout<<num<<endl;
            return;
        } else {
            n -= cur;
        }
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
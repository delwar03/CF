#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q; cin>>n>>q;
    string s; cin>>s;

    int cnt = 0;
    for(int i = 0; i < n - 2; i++) {
        if(s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') cnt++;
    }

    // cerr<<"cnt: "<<cnt<<endl;

    while(q--) {
        int i; char ch; cin>>i>>ch;
        --i;
        if(s[i] == ch) {
            //
        } else {
            if(s[i] == 'A') {
                if(i + 2 < n && s[i + 1] == 'B' && s[i + 2] == 'C') cnt--; 
            } else if(s[i] == 'B') {
                if(i - 1 >= 0 && i + 1 < n && s[i - 1] == 'A' && s[i + 1] == 'C') cnt--;
            } else if(s[i] == 'C') {
                if(i - 2 >= 0 && s[i - 1] == 'B' && s[i - 2] == 'A') cnt--;
            } else {
                //
            }
            // cerr<<"cnt: "<<cnt<<endl;
            s[i] = ch;
            if(s[i] == 'A') {
                if(i + 2 < n && s[i + 1] == 'B' && s[i + 2] == 'C') cnt++; 
            } else if(s[i] == 'B') {
                if(i - 1 >= 0 && i + 1 < n && s[i - 1] == 'A' && s[i + 1] == 'C') cnt++;
            } else if(s[i] == 'C') {
                if(i - 2 >= 0 && s[i - 1] == 'B' && s[i - 2] == 'A') cnt++;
            } else {
                //
            }
        }
        cout<<cnt<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
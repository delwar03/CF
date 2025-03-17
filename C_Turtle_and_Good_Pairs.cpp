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
    string s; cin>>s;
    vector<int> fq(26);
    for(auto ch : s) fq[ch - 'a']++;

    for(int i = 0; i < n; i++) {
        int f = 1;
        for(int j = 0; j < 26; j++) {
            if(fq[j]) {
                char cur = j + 'a';
                cout<<cur;
                fq[j]--;
                f = 0;
            }
        }
        if(f) break;
    }
    cout<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
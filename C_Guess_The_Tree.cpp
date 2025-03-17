#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
#define ff first
#define ss second
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; cin>>n;
    vector<pair<int, int>> edges;

    auto que = [&] (int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        int res; cin>>res;
        return res;
    };

    int a = 1, b = 2;
    
    while(1) {
        int x = que(b, a);
        if(x == a || x == b) {
            edges.push_back({a, b});
            a = 1;
            b++;
        } else {
            a = x;
        }
        if(b > n) break;
    }

    assert(edges.size() == n - 1);

    cout<<"! ";
    for(auto it : edges) cout<<it.ff<<" "<<it.ss<<" "; cout<<endl;
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
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 10;
const int INF = 1e18 + 10;

vector<int> m;

void Euclid(int a, int b) {
    if(a == 0 || b == 0) return;

    int k = a / b;
    m.push_back(k);
    a -= k * b;

    Euclid(b, a);
}

void solve() {
    int p, q; cin>>p>>q;
    int n; cin>>n;
    vector<int> v(n);
    for(auto &x : v) cin>>x;

    if(n > 1 && v.back() == 1) {
        v.pop_back();
        n--;
        v[n - 1]++;
    }

    m.clear();

    Euclid(p, q);

    if(m.size() != n) {
        cout<<"NO"<<endl;
    } else {
        for(int i = 0; i < n; i++) {
            if(v[i] != m[i]) {
                cout<<"NO"<<endl;
                return;
            }
        }
        cout<<"YES"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1; //cin>>t;
    for(int c = 1; c <= t; c++) {
        // cerr<<"Case "<<c<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
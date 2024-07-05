#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    vector<int> k(n);
    auto lcm = [&] (int a, int b) {
        return a * b / __gcd(a, b);
    };
    int l = 1;
    for(auto &x : k) {
        cin>>x;
        l = lcm(l, x);
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        k[i] = l / k[i];
        sum += k[i];
    }

    if(sum >= l) {
        cout<<-1<<endl;
    } else {
        for(auto it : k) cout<<it<<" "; cout<<endl;
    }
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
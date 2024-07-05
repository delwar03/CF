#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

int binPow(int a, int b, int m) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int inv(int a, int m) {
    return binPow(a, m - 2, m);
}


void solve() {
    int a, b, p, x; cin>>a>>b>>p>>x;
    int ans = 0;

    for(int j = 1; j <= p - 1; j++) {
        int y = (b * inv(binPow(a, j, p), p)) % p;
        int i = (p - 1) * ((j - y + p) % p) + j;
        if(i <= x) ans += (x - i) / (p * (p - 1)) + 1;
    }
    cout<<ans<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 
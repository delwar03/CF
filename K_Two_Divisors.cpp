#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int M = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

int prime[N];

void solve() {
    int n; cin>>n;
    vector<int> v(n);
    vector<int> d1, d2;
    for(auto &x : v) {
        cin>>x;

        int cur = 1, p = prime[x];

        while(x % p == 0) {
            cur *= p;
            x /= p;
        }

        if(x == 1) { // Single prime factor
            d1.push_back(-1);
            d2.push_back(-1);
        } else {
            d1.push_back(cur);
            d2.push_back(x);
        }
    }

    for(auto x : d1) cout<<x<<" "; cout<<endl;
    for(auto x : d2) cout<<x<<" ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    for(int i = 1; i < N; i++) prime[i] = i;

    for(int i = 2; i < N; i++) {
        if(prime[i] == i) {
            for(int j = i * i; j < N; j += i) {
                prime[j] = i;
            }
        }
    }

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
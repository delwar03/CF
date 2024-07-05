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

int PHI[N], F[N], SUM[N];

void solve() {
    int n;
    while(cin >> n && n) {
        cout<<SUM[n]<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    for(int i = 1; i < N; i++) PHI[i] = i;

    for(int i = 2; i < N; i++) {
        if(PHI[i] == i) {
            for(int j = i; j < N; j += i) {
                PHI[j] -= PHI[j] / i;
            }
        }
    }

    // for(int i = 1; i < N; i++) 

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            F[j] += i * PHI[j / i];
        }
    }

    for(int i = 1; i < N; i++) {
        SUM[i] = SUM[i - 1] + F[i] - i;
    }

    // for(int i = 1; i <= 100; i++) {
    //     cerr<<F[i]<<" "; 
    // }

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
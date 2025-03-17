#include <bits/stdc++.h>
#define int long long
// #define endl '\n'
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e18 + 10;

mt19937_64 rng {chrono::steady_clock::now().time_since_epoch().count()};

void solve() {
    int n; cin>>n;
    if(n <= 6) {
        if(n == 1) {
            cout<<1<<endl;
            cout<<"1"<<endl;
        } else if(n == 2) {
            cout<<2<<endl;
            cout<<"1 2"<<endl;
        } else if(n == 3) {
            cout<<2<<endl;
            cout<<"1 2 2"<<endl;
        } else if(n == 4) {
            cout<<3<<endl;
            cout<<"1 2 2 3"<<endl;
        } else if(n == 5) {
            cout<<3<<endl;
            cout<<"1 2 2 3 3"<<endl;
        } else {
            cout<<4<<endl;
            cout<<"1 2 2 3 3 4"<<endl;
        }
    } else {
        cout<<4<<endl;
        vector<int> col(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(col[i]) continue;
            if(i % 2 == 0) {
                col[i] = 1;
                if((i ^ 2) <= n && !col[i ^ 2]) {
                    col[i ^ 2] = 2;
                }
            } else {
                col[i] = 3;
                if((i ^ 2) <= n && !col[i ^ 2]) {
                    col[i ^ 2] = 4;
                }
            }
        }

        for(int i = 1; i <= n; i++) cout<<col[i]<<" "; cout<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto isPrime = [&] (int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    };

    // for(int i = 1; i <= 100; i++) {
    //     for(int j = 1; j <= 100; j++) {
    //         int x = i ^ j;
    //         if(isPrime(x)) {
    //             cerr<<i<<" "<<j<<endl;
    //         }
    //     }
    // }

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

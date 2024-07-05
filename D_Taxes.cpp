#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;

    auto isPrime = [&] (int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    };

    if(n % 2 == 0) {
        if(n == 2) {
            cout<<1<<endl;
        } else {
            cout<<2<<endl;
        }
    } else {
        if(isPrime(n)) {
            cout<<1<<endl;
        } else if(isPrime(n - 2)) {
            cout<<2<<endl;
        } else {
            cout<<3<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": "<<endl;
        solve();
    }
}
 
/*
i/p:  
    1 -> 1
    2 -> 2
    4 -> 4
    5 -> 2
o/p: 
*/ 

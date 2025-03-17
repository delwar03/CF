#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 504;
const int N = 2e5 + 10;
const int INF = 1e9 + 10;

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

    auto nextPrime = [&] (int n) {
        int tmp = n;
        while(1) {
            tmp++;
            if(isPrime(tmp)) {
                return tmp;
            }
        }
    };


    if(isPrime(n)) {
        cout<<n * nextPrime(n)<<endl;
    } else {
        int x = nextPrime(n);
        int y = nextPrime(x);
        cout<<x * y<<endl;
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
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M = 1e9 + 7;
const int N = 1e6 + 10;
const int INF = 1e15 + 10;

int fib[40];

void solve() {
    int k; cin>>k;
    string s = "";
    for(int i = 39; i >= 0; i--) {
        if(k >= fib[i]) {
            s += "1";
            k -= fib[i];
        } else if(s.size()) {
            s += "0";
        }
    }
    cout<<s<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fib[0] = 1;
    fib[1] = 2;
    for(int i = 2; i < 40; i++) fib[i] = fib[i - 1] + fib[i - 2];

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
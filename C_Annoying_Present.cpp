#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1.5e7 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n, m; cin>>n>>m;
    
    int sum = 0;

    while(m--) {
        int x, d; cin>>x>>d;
        sum += n * x;
        if(d >= 0) {
            sum += n * (n - 1) * d / 2.0;
        } else {
            int p = n / 2;
            int sm = p * (p + 1);
            if(n % 2 == 0) sm -= p;
            sum += sm * d;
        }
    }
    double avg = 1.0 * sum / n;
    cout<<fixed<<setprecision(15)<<avg<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
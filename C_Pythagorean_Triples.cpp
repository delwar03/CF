#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

/*
    Pythagorian Triplets:

    n -> odd:
        (n ^ 2 - 1) / 2, (n ^ 2 + 1) / 2
    n -> even:
        ((n ^ 2) / 4) - 1, ((n ^ 2) / 4) + 1

*/

void solve() {
    int n; cin>>n;
    if(n < 3) {
        cout<<-1<<endl;
    } else {
        if(n & 1) {
            cout<<(n * n - 1) / 2<<" "<<(n * n + 1) / 2<<endl;
        } else {
            cout<<(n * n) / 4 - 1<<" "<<(n * n) / 4 + 1<<endl;
        }
    }
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
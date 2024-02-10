#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e15 + 10;

void solve() {
    int a, b, r; cin>>a>>b>>r;
    if(a < b) swap(a, b);
    bool hobe = false;
    int x = 0, y = 0;

    for(int i = 63; i >= 0; i--) {
        int a_bit = (a >> i) & 1;
        int b_bit = (b >> i) & 1;

        // if(a_bit == b_bit && r_bit) hobe = true;
        // if(a_bit == b_bit) continue;
        // cout<<a_bit<<" "<<b_bit<<endl;

        if(a_bit && !b_bit) {
            if(!hobe) {
                hobe = true;
            } else {
                if(x + (1LL << i) <= r) {
                    x += (1LL << i);
                }
            }
        }
    }
    assert(x <= r);
    // cout<<x<<endl;
    cout<<(a ^ x) - (b ^ x)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        // cout<<"Scenario #"<<c++<<":\n";
        solve();
    }
    return 0;
}
 
/*
i/p: 
o/p: 
*/
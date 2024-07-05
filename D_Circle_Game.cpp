#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n, k; cin>>n>>k;
    int x = 0, y = 0;
    while(1) {
        if(x <= y && (x + k) * (x + k) + y * y <= n * n) {
            x += k;
        } else if(x > y && x * x + (y + k) * (y + k) <= n * n) {
            y += k;
        } else {
            break;
        }
    }

    cout<<(x == y ? "Utkarsh" : "Ashish")<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
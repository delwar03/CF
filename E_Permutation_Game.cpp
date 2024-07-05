#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin>>v[i];
    int a = 0, b = 0, c = 0;
    for(int i = 1; i <= n; i++) {
        if(i != v[i] && (n - i + 1) != v[i]) {
            c++;
        } else {
            if(i != v[i]) {
                a++;
            } else if((n - i + 1) != v[i]) {
                b++;
            }
        }
    }
    if(a + c <= b) {
        cout<<"First"<<endl;
    } else if(b + c < a) {
        cout<<"Second"<<endl;
    } else {
        cout<<"Tie"<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}

/*
i/p: 
o/p: 
*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int prm = 31;
const int N = 3e5 + 10;
const int INF = 1e18 + 10;

void solve() {
    int n; cin>>n;
    vector<int> v(n + 1);
    int mn = INF, ind = -1;
    for(int i = 1; i <= n; i++) {
        cin>>v[i];
        if(v[i] < mn) {
            mn = v[i];
            ind = i;
        }
    }
    
    if(n & 1) {
        cout<<"Mike"<<endl;
    } else {
        if(ind & 1) {
            cout<<"Joe"<<endl;
        } else {
            cout<<"Mike"<<endl;
        }
    }
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
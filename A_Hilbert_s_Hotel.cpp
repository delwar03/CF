#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e7 + 10;
const int INF = 1e15 + 10;

void solve() {
    int n; cin>>n;
    set<int> st;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        x %= n;
        if(x < 0) x += n;
        st.insert((i + x) % n);
    }

    if(st.size() == n) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
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
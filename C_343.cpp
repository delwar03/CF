#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
const int INF = 1e15 + 10;

void solve() {
    set<int> st;

    auto isPalindrom = [&](string s) {
        int l = s.size();
        for(int i = 0; i < l / 2; i++) {
            if(s[i] != s[l - i - 1]) return false;
        }
        return true;
    };

    for(int i = 0; i < N; i++) {
        int cube = i * i * i;
        string str = to_string(cube);
        if(isPalindrom(str)) {
            st.insert(cube);
        }
    }
    // for(auto it : st) cerr<<it<<" "; cerr<<endl;
    int n; cin>>n;
    auto it = st.upper_bound(n);
    cout<<*(--it)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 
/*
i/p:  
o/p: 
*/ 